package problems

// P9 finds the product of a, b, and c where a, b, and c are a Pythagoream triplet equal to 1000
func P9() uint64 {
	// Useing euclids formula to reduce number of calculations
	// a = m^2 - n^2
	// b = 2mn
	// c = m^2 + n^2
	// after some algebra
	// 2m^2 + 2mn = 1000

	aFunc := func(m, n uint64) uint64 {
		return (m * m) - (n * n)
	}
	bFunc := func(m, n uint64) uint64 {
		return 2 * m * n
	}
	cFunc := func(m, n uint64) uint64 {
		return (m * m) + (n * n)
	}

	checkFunc := func(m, n uint64) bool {
		return (2*(m*m) + 2*m*n) == 1000
	}

	var m, n uint64
	var product uint64
	for n = 1; n < 1000; n++ {
		// m must be greater than n
		for m = n + 1; m < 1000; m++ {
			if checkFunc(m, n) {
				product = aFunc(m, n) * bFunc(m, n) * cFunc(m, n)
				break
			}
		}
	}

	return product
}
