func topKFrequent(nums []int, k int) []int {
	res := []int{}

	freqs := make(map[int]int)
	buckets := make([][]int, len(nums))

	for _, num := range nums {
		freqs[num]++
	}

	for num, freq := range freqs {
		buckets[freq - 1] = append(buckets[freq - 1], num)
	}

	fmt.Println(freqs)
	fmt.Println(buckets)
	for i := len(buckets) - 1; i >= 0; i-- {
		for _, val := range buckets[i] {
			res = append(res, val)
			k--
			if k == 0 {
				return res
			}
		}
	}

	return res

}
