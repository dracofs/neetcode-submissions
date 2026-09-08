func findMaxConsecutiveOnes(nums []int) int {
	maxl, currl := 0, 0

	for _, num := range nums {
		if num != 1 {
			currl = 0 
		} else {
			currl++
		}
		maxl = max(maxl, currl)
	}

	return maxl
}
