package problems

import (
	"os"
	"testing"
)

func TestP8(t *testing.T) {
	buf, err := os.ReadFile("../../data/p8.txt")
	if err != nil {
		t.Error(err)
	}
	if P8(string(buf[:len(buf)-1])) != 23514624000 {
		t.Fail()
	}
}
