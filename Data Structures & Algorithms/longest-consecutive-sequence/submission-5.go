func longestConsecutive(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	set := make(map[int]bool)

	for _, num := range nums {
		set[num] = true
	}

	best := 1

	for _, num := range nums {
		curr := 0
		if there := set[num - 1]; !there {
			// num is a seq start
			for set[num] {
				curr++
				num++
			}
		}
		best = max(best, curr)
	}

	return best
}
