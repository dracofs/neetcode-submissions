func productExceptSelf(nums []int) []int {
	res := make([]int, len(nums))
	left := make([]int, len(nums))
	right := make([]int, len(nums))
	left[0] = 1
	right[len(nums) - 1] = 1

	for i := 1; i < len(nums); i++ {
		left[i] = left[i - 1] * nums[i - 1]
		right[len(nums) - i - 1] = right[len(nums) - i] * nums[len(nums) - i]
	}

	for i := 0; i < len(nums); i++ {
		res[i] = left[i] * right[i]
	}

	return res
}
