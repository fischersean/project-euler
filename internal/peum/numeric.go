package peum

func AbsInt64(n int64) int64 {
	if n < 0 {
		n *= -1
	}
	return n
}
