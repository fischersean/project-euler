package problems

import (
	"github.com/fischersean/project-euler/internal/peum"
	"math"
)

// P3 returns the largest prime factor of 600,851,475,143
func P3() int {

	N := 600851475143
	// check all numbers less than the sqrt root of N
	max := int(math.Pow(float64(N), 0.5))

	largestFactor := 1
	for i := 3; i < max; i += 2 {
		if N%i == 0 {
			if peum.IsPrime(uint64(i)) {
				largestFactor = int(i)
			}
		}
	}

	return largestFactor
}
