package problems

import (
	"testing"
)

func TestP5(t *testing.T) {
	if P5() != 232792560 {
		t.Fail()
	}
}

func BenchmarkP5(b *testing.B) {
	for i := 0; i < b.N; i++ {
		P5()
	}
}
