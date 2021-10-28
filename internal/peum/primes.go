package peum

// IsPrime returns whether of not the given number is prime
func IsPrime(n uint64) bool {
	if n <= 3 {
		return n > 1
	}
	if n%2 == 0 || n%3 == 0 {
		return false
	}
	var i uint64
	for i = 5; i*i <= n; i += 6 {
		if n%i == 0 || n%(i+2) == 0 {
			return false
		}
	}
	return true
}

// LCM returns the least common multiple of n and m
func LCM(n, m uint64) uint64 {
	return (n * m) / GCD(n, m)
}

// LCMSet returns the least common multiple of a set of integers
func LCMSet(s []uint64) uint64 {
	n := len(s)
	a := s[n-1]
	var b uint64
	if n == 1 {
		b = s[0]
	} else {
		b = LCMSet(s[:n-1])
	}
	return LCM(a, b)
}

// GCD implements euclid's greates common divisor algorithm
func GCD(n, m uint64) uint64 {
	if m == 0 {
		return n
	}
	return GCD(m, n%m)
}

func rhoG(x, n int64) int64 {
	return (x*x + 1) % n
}

// PrimeFactorRho implements Pollard's rho algorithm
func PrimeFactorRho(n, d int64) int64 {
	var x, y int64 = 2, 2
	for d == 1 {
		x = rhoG(x, n)
		y = rhoG(rhoG(y, n), n)
		d = int64(GCD(uint64(AbsInt64(x-y)), uint64(n)))
	}
	return d
}
