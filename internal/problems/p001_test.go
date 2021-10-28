package problems

import (
	"testing"
)

func TestP1(t *testing.T) {
	if P1() != 233168 {
		t.Fail()
	}
}
