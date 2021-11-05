package problems

import (
	"bytes"
	"fmt"
	"os"
	"testing"
)

const GRID_DIM = 20

func parseP11File() ([][]int, error) {
	buf, err := os.ReadFile("../../data/p11.txt")
	if err != nil {
		return nil, err
	}
	reader := bytes.NewReader(buf)

	retGrid := make([][]int, 20)
	for i := 0; i < GRID_DIM; i++ {
		retGrid[i] = make([]int, 20)
		for j := 0; j < GRID_DIM; j++ {
			// straight up just ignoring the error thrown when we hit the newline
			// we have tight control over the input file so risk is low
			fmt.Fscanf(reader, "%02d", &retGrid[i][j])
		}
	}
	return retGrid, nil
}

func TestP11(t *testing.T) {
	input, err := parseP11File()
	if err != nil {
		t.Error(err)
	}
	if P11(input) != 70600674 {
		t.Fail()
	}
}
func BenchmarkP11(b *testing.B) {
	input, err := parseP11File()
	if err != nil {
		b.Error(err)
	}
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		P11(input)
	}
}
