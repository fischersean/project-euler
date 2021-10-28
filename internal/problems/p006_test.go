package problems

import (
	"testing"
)

func TestP6(t *testing.T) {
	if P6() != 25164150 {
		t.Fail()
	}
}

func BenchmarkP6(b *testing.B) {
	for i := 0; i < b.N; i++ {
		P6()
	}
}
