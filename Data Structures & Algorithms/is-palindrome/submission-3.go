

func isPalindrome(s string) bool {	
	f := ""
	for index := range s {
		if unicode.IsLetter(rune(s[index])) || unicode.IsDigit(rune(s[index])) {
			f += string(s[index])
		}
	}
	f = strings.ToLower(f)
	fmt.Printf("Filtered string is: %s\n", f)
	left := 0; right := len(f) - 1
	for left < right {
		fmt.Printf("Left: %c, Right: %c\n", f[left], f[right])
		if f[left] != f[right] {
			return false
		}
		left++
		right--
	}

	return true
}
