package problems

import (
	"testing"
)

func TestP7(t *testing.T) {
	if P7() != 104743 {
		t.Fail()
	}
}
