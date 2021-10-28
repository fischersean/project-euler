package problems

import (
	"testing"
)

func TestP2(t *testing.T) {
	if P2() != 4613732 {
		t.Fail()
	}
}

func BenchmarkP2(b *testing.B) {
	for i := 0; i < b.N; i++ {
		P2()
	}
}
