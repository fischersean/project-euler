package problems

import (
	"github.com/fischersean/project-euler/internal/peum"
)

// P10 returns the sum of the primes below 2 million
func P10() uint64 {

	// starting out at 2 to overcome the issue of adding 2 to an even starting number
	var runningSum uint64 = 2

	var i uint64
	for i = 3; i < 2000000; i += 2 {
		if peum.IsPrime(i) {
			runningSum += i
		}
	}

	return runningSum
}
