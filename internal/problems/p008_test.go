package problems

import (
	"os"
	"testing"
)

func TestP8(t *testing.T) {
	buf, err := os.ReadFile("../../data/p8.txt")
	if err != nil {
		t.Error(err)
	}
	if P8(string(buf[:len(buf)-1])) != 23514624000 {
		t.Fail()
	}
}

func BenchmarkP8(b *testing.B) {
	buf, err := os.ReadFile("../../data/p8.txt")
	if err != nil {
		b.Error(err)
	}
	input := string(buf[:len(buf)-1])
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		P8(input)
	}
}
