package problems

import (
	"testing"
)

func TestP1(t *testing.T) {
	if P1() != 233168 {
		t.Fail()
	}
}

func BenchmarkP1(b *testing.B) {
	for i := 0; i < b.N; i++ {
		P1()
	}
}
