package problems

import (
	"testing"
)

func TestP10(t *testing.T) {
	if P10() != 142913828922 {
		t.Fail()
	}
}

func BenchmarkP10(b *testing.B) {
	for i := 0; i < b.N; i++ {
		P10()
	}
}
