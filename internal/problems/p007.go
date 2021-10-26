package problems

import (
	"github.com/fischersean/project-euler/internal/peum"
)

// P7 returns the 10001st prime
func P7() uint64 {
	N := 10001
	i := 1           // n-th prime
	var n uint64 = 1 // first prime candidate
	// Using the brute force approach for now. will optimize later
	for i < N {
		n += 2
		if peum.IsPrime(n) {
			i++
		}
	}
	return n
}
