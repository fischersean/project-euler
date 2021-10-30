package main

import (
	"errors"
	"fmt"
	"os"
	"strconv"
)

var ProblemDir string = "internal/problems"

func problemFileText(pNum int) string {
	pTemplate := fmt.Sprintf("package problems\nfunc P%d() uint64 {\n\treturn 0\n}", pNum)
	return pTemplate
}

func testFileText(pNum int) string {
	headTemplate := "package problems\n\nimport(\n\t\"testing\"\n)"
	testTemplate := fmt.Sprintf("func TestP%d(t *testing.T) {\n\tif P%d() != 1 {\n\t\tt.Fail()\n\t}\n}", pNum, pNum)
	benchmarkTemplate := fmt.Sprintf("func BenchmarkP%d(b *testing.B) {\n\tfor i := 0; i < b.N; i++ {\n\t\tP%d()\n\t}\n}", pNum, pNum)
	return fmt.Sprintf("%s\n%s\n%s", headTemplate, testTemplate, benchmarkTemplate)
}

func fileExists(fname string) (bool, error) {
	_, err := os.Stat(fname)
	if err == nil {
		return true, nil
	}
	if errors.Is(err, os.ErrNotExist) {
		return false, nil
	}
	return false, err
}

// createFiles creates 2 files, a problem file and a test file
func createFiles(pNum int) error {

	pString := fmt.Sprintf("p%03d", pNum)

	// create problem file
	pfName := fmt.Sprintf("%s/%s.go", ProblemDir, pString)
	if e, err := fileExists(pfName); e || err != nil {
		if err != nil {
			return err
		}
		return os.ErrExist
	}
	pf, err := os.Create(pfName)
	if err != nil {
		return err
	}
	defer pf.Close()

	// create test file
	tfName := fmt.Sprintf("%s/%s_test.go", ProblemDir, pString)
	if e, err := fileExists(tfName); e || err != nil {
		if err != nil {
			return err
		}
		return os.ErrExist
	}
	tf, err := os.Create(tfName)
	if err != nil {
		return err
	}
	defer tf.Close()

	// populate files
	_, err = pf.WriteString(problemFileText(pNum))
	if err != nil {
		return err
	}

	_, err = tf.WriteString(testFileText(pNum))
	return err
}

func main() {
	args := os.Args
	if len(args) != 2 {
		fmt.Println("No problem number provided")
		return
	}
	pName := args[1]
	pNum, err := strconv.Atoi(pName)
	if err != nil {
		fmt.Println(err)
		return
	}
	err = createFiles(pNum)
	if err != nil {
		fmt.Println(err)
		return
	}
}
