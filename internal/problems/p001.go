package problems

// P1 calculates the sum of all multiples of 3 or 5 below 1000
func P1() int {

	runningSum := 0
	for i := 3; i < 1000; i++ {
		if i%3 == 0 || i%5 == 0 {
			runningSum += i
		}
	}

	return runningSum
}
