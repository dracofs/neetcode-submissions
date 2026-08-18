var dirs [][]int = [][]int{ {-1, 0}, {1, 0}, {0, -1}, {0, 1}, }

func exist(board [][]byte, word string) bool {
	// iterate till find matching first char, 
	for i, row := range board {
		for j, elem := range row {
			if elem == word[0] {
				temp := board[i][j]
				board[i][j] = '.'
				if dfs(board, word[1:], i, j) {
					return true
				}
				board[i][j] = temp
			}
		}
	}
	return false
}

func dfs(board [][]byte, word string, i, j int) bool {
	if len(word) == 0 {
		return true
	}

	for _, dir := range dirs {
		newr := i + dir[0]
		newc := j + dir[1]

		if (newr >= 0 && newr < len(board) && newc >= 0 && newc < len(board[0]) && board[newr][newc] == word[0]) {
			// Keep going down this path
			temp := board[newr][newc]
			board[newr][newc] = '.'
			if dfs(board, word[1:], newr, newc) {
				return true
			}
			board[newr][newc] = temp
		}
	}

	return false
}
