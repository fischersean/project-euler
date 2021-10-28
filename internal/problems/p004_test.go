package problems

import (
	"testing"
)

func TestP4(t *testing.T) {
	if P4() != 906609 {
		t.Fail()
	}
}

func BenchmarkP4(b *testing.B) {
	for i := 0; i < b.N; i++ {
		P4()
	}
}
