func twoSum(nums []int, target int) []int {
    mmap := make(map[int]int)

    for index, num := range nums {
        find := target - num
        prev, ok := mmap[find]
        if ok {
            return []int{prev, index}
        }
        mmap[num] = index
    }

    return []int{-1, -1}

}
