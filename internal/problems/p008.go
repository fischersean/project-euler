package problems

import (
	"strconv"
)

// P8 finds the largest product of 13 adjacent numbers from the input string
func P8(input string) uint64 {
	nAdj := 13
	// convert input string to int slice
	set := make([]uint64, len(input))
	for i, s := range input {
		n, err := strconv.Atoi(string(s))
		if err != nil {
			return 0
		}
		set[i] = uint64(n)
	}

	var runningProduct uint64
	var maxProduct uint64 = 1
	// find initial product
	for i := nAdj; i < len(set); i++ {
		runningProduct = 1
		if set[i] == 0 {
			// small optimization for cases where we land on 0.
			// if we land on 0 we know for sure the runningProduct will be 0
			i += nAdj
			continue
		}
		for j := nAdj - 1; j >= 0; j-- {
			runningProduct *= set[i-j]
		}
		if runningProduct > maxProduct {
			maxProduct = runningProduct
		}
	}
	return maxProduct
}
