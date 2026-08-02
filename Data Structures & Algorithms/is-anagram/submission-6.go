func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }

    var mmap [26]int

    for index, _ := range s {
        mmap[s[index] - 'a']++
        mmap[t[index] - 'a']--
    }

    for _, count := range mmap {
        if count != 0 {
            return false 
        } 
    }
    return true
}
