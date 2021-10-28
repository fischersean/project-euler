package peum

import (
	"testing"
)

func TestGCD(t *testing.T) {
	if GCD(54, 24) != 6 {
		t.Fail()
	}
}

func TestPrimeFactorRho(t *testing.T) {
	if PrimeFactorRho(10403, 1) != 101 {
		t.Fail()
	}
}

func TestIsPrime(t *testing.T) {
	if IsPrime(100) {
		t.Fail()
	}

	if !IsPrime(7) {
		t.Fail()
	}

	if IsPrime(486847) {
		t.Fail()
	}
}

func TestLCM(t *testing.T) {
	if LCM(21, 6) != 42 {
		t.Fail()
	}
}

func TestLCMSet(t *testing.T) {
	if LCMSet([]uint64{1, 2, 3}) != 6 {
		t.Fail()
	}
	if LCMSet([]uint64{2, 3, 4}) != 12 {
		t.Fail()
	}
}
