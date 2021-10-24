package problems

// P2 finds the sum of the even-valued terms for the Fibonacci numbers up to 4 million
func P2() int {

	n, m := 1, 2
	var tmp int
	runningSum := 0

	for m < 4000000 {
		if m%2 == 0 {
			runningSum += m
		}
		tmp = m
		m += n
		n = tmp
	}

	return runningSum
}
