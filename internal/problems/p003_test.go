package problems

import (
	"testing"
)

func TestP3(t *testing.T) {
	if P3() != 6857 {
		t.Fail()
	}
}

func BenchmarkP3(b *testing.B) {
	for i := 0; i < b.N; i++ {
		P3()
	}
}
