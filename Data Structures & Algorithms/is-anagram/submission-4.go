func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }

    mmap := make(map[byte]int, 26)

    for index, _ := range s {
        mmap[s[index]] = mmap[s[index]] + 1
        mmap[t[index]] = mmap[t[index]] - 1
    }

    for _, count := range mmap {
        if count != 0 {
            return false 
        } 
    }
    return true
}
