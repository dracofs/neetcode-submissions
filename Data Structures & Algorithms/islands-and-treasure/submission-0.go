func islandsAndTreasure(grid [][]int) {
    dirs := [4][2]int{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} }
    treasures := [][2]int{}
    inf := 2147483647
    for r, row := range grid {
        for c, element := range row {
            if element == 0 {
                treasures = append(treasures, [2]int{r, c})
            }
        }
    }

    q := treasures
    for len(q) != 0 {
        r, c := q[0][0], q[0][1]
        q = q[1:]
        for _, dir := range dirs {
            row := r + dir[0]
            col := c + dir[1]
            if row >= 0 && row < len(grid) && col >= 0 && col < len(grid[0]) && (grid[row][col] == inf) {
                q = append(q, [2]int{ row, col })
                grid[row][col] = grid[r][c] + 1
            }
        }
    }
}
