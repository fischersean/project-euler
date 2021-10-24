package problems

import (
	"testing"
)

func TestP4(t *testing.T) {
	if P4() != 906609 {
		t.Fail()
	}
}
