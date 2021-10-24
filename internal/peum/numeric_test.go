package peum

import (
	"testing"
)

func TestAbsInt64(t *testing.T) {
	if AbsInt64(-1) != 1 {
		t.Fail()
	}
}
