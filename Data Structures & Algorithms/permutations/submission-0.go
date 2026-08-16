func permute(nums []int) [][]int {
    res := [][]int{}
    gen(&res, nums, 0)
    return res
}

func gen(res *[][]int, nums []int, index int){
    if (index == len(nums) - 1) {
        *res = append(*res, nums)
        return
    }

    for i := index; i < len(nums); i++ {
        // not swap and recurse
        nums[i], nums[index] = nums[index], nums[i]
        gen(res, nums, index + 1)
        nums[i], nums[index] = nums[index], nums[i]
    }
}