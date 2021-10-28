package problems

import (
	"testing"
)

func TestP9(t *testing.T) {
	if P9() != 31875000 {
		t.Fail()
	}
}
