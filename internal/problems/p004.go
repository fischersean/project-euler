package problems

import (
	"fmt"
	"strconv"
)

func isPalindrome(n int) bool {

	strN := fmt.Sprint(n)
	reversedStrN := ""
	for _, v := range strN {
		reversedStrN = string(v) + reversedStrN
	}

	reversedN, _ := strconv.Atoi(reversedStrN)

	return reversedN == n
}

// P4 finds the largest palindrome made from the product of two 3-digit numbers.
func P4() int {
	largestPalindrome := 0
	for i := 999; i >= 100; i-- {
		for j := 999; j >= 100; j-- {
			prod := i * j
			if isPalindrome(prod) && prod > largestPalindrome {
				largestPalindrome = prod
			}
		}
	}
	return largestPalindrome
}
