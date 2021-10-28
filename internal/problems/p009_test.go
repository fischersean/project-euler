package problems

import (
	"testing"
)

func TestP9(t *testing.T) {
	if P9() != 31875000 {
		t.Fail()
	}
}

func BenchmarkP9(b *testing.B) {
	for i := 0; i < b.N; i++ {
		P9()
	}
}
