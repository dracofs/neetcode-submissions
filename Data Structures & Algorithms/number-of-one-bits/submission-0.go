func hammingWeight(n int) int {
	res := 0
	cp := uint32(n)
	for cp > 0 {
		if cp % 2 == 1 {
			res++
		}
		cp = cp >> 1
	}
	return res
}
