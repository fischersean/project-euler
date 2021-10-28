package problems

import (
	"github.com/fischersean/project-euler/internal/peum"
)

// P5 returns the smallest positive number that is evenly divisible by all of the numbers from 1 to 20
func P5() int {
	// This problem is essentially asking to find the least commong multiple of the set
	// {1, 2, 3,..., 20}
	set := make([]uint64, 20)
	for i := 0; i < 20; i++ {
		set[i] = uint64(i) + 1
	}
	return int(peum.LCMSet(set))
}
