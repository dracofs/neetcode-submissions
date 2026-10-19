func groupAnagrams(strs []string) [][]string {
	res := make([][]string, 0, len(strs))
	buckets := make(map[string][]string)

	for _, str := range strs {

		curr := []rune{}
		count := make([]int, 26)

		// count schars
		for _, char := range str {
			count[char - 'a']++
		}

		for i, val := range count {
			curr = append(curr, rune('a' + i), rune(val) + '0')
		}
		conv := string(curr)
		buckets[conv] = append(buckets[conv], str)
	}

	for _, bucket := range buckets {
		res = append(res, bucket)
	}

	return res
}
