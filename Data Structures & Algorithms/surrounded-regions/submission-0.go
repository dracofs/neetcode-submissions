
func solve(board [][]byte) {
    visited := make([][]bool, len(board))
    for row := range visited {
        visited[row] = make([]bool, len(board[0]))
    } 
    fmt.Printf("Default value is: %v", visited[0][0])
    for r, row := range board {
        for c, element := range row {
            if element == 'O' && !visited[r][c] {
                bfs(&board, &visited, [2]int{r, c})
            }
        }
    }

}

func bfs(board *[][]byte, visited*[][]bool, coord [2]int) {
    dirs := [][2]int{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} }
    q := [][2]int{ coord }
    o := [][2]int{ coord }

    var top [2]int
    var row int
    var col int
    var r int
    var c int
    for len(q) > 0 {
        top = q[0]
        q = q[1:]

        row = top[0]
        col = top[1]

        for _, dir := range dirs {
            r = row + dir[0]
            c = col + dir[1]

            if r >= 0 && r < len(*board) && c >= 0 && c < len((*board)[0]) && (*board)[r][c] == 'O' && !(*visited)[r][c] {
                (*visited)[r][c] = true
                q = append(q, [2]int{r, c})
                o = append(o, [2]int{r, c})
            }
        }
    }
    flag := false
    for _, coord := range o {
        if coord[0] == 0 || coord[0] == len(*board) - 1 || coord[1] == 0 || coord[1] == len((*board)[0]) - 1 {
            flag = true
        }
    }

    if !flag {
        for _, coord := range o {
            (*board)[coord[0]][coord[1]] = 'X'
        }
    } else {
        for _, coord := range o {
            (*visited)[coord[0]][coord[1]] = true
        }
    }
}
