package problems

import (
	"testing"
)

func TestP7(t *testing.T) {
	if P7() != 104743 {
		t.Fail()
	}
}

func BenchmarkP7(b *testing.B) {
	for i := 0; i < b.N; i++ {
		P7()
	}
}
