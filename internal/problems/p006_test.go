package problems

import (
	"testing"
)

func TestP6(t *testing.T) {
	if P6() != 25164150 {
		t.Fail()
	}
}
