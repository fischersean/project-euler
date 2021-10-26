package problems

// P6 returns the difference between the squared sum and the sum of squares
func P6() uint64 {

	var N uint64 = 100
	// find the squared sum (https://en.wikipedia.org/wiki/Arithmetic_progression#Sum)
	var sum uint64 = (N + 1) * N / 2
	// find the sum of squares (https://wiki.math.ucr.edu/index.php/An_Introduction_to_Mathematical_Induction:_The_Sum_of_the_First_n_Natural_Numbers,_Squares_and_Cubes.#The_Sum_of_the_first_n_Squares)
	var sumOfSquares uint64 = (N + 1) * (2*N + 1) * N / 6

	return (sum * sum) - sumOfSquares
}
