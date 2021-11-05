package problems

func diagonalProd(grid [][]int, x int, y int, l int) uint64 {
	var maxProd uint64 = 1

	// down and right
	if x+l < len(grid) && y+l < len(grid) {
		for i := 0; i < l; i++ {
			maxProd *= uint64(grid[x+i][y+i])
		}
	}

	var runningProduct uint64 = 1
	// down and left
	if x+l < len(grid) && y-l >= 0 {
		for i := 0; i < l; i++ {
			runningProduct *= uint64(grid[x+i][y-i])
		}
	}
	if runningProduct > maxProd {
		maxProd = runningProduct
	}

	return maxProd
}

func verticalProd(grid [][]int, x int, y int, l int) uint64 {
	var runningProduct uint64 = 1
	for i := 0; i < l; i++ {
		runningProduct *= uint64(grid[x+i][y])
	}
	return runningProduct
}

func horizonatalProd(grid [][]int, x int, y int, l int) uint64 {
	var runningProduct uint64 = 1
	for i := 0; i < l; i++ {
		runningProduct *= uint64(grid[x][y+i])
	}
	return runningProduct
}

// P11 returns the largest product of 4 adjacent levels from the provided number grid
func P11(grid [][]int) uint64 {
	serchLen := 4
	gridSize := len(grid)

	var maxProd uint64 = 1
	var vertProd, horiProd, diagProd uint64
	for i := 0; i < gridSize; i++ {
		for j := 0; j < gridSize; j++ {
			// diagonal
			if i <= gridSize-serchLen && j <= gridSize-serchLen {
				diagProd = diagonalProd(grid, i, j, serchLen)
			} else {
				diagProd = 1
			}
			// vertical
			if i <= gridSize-serchLen {
				vertProd = verticalProd(grid, i, j, serchLen)
			} else {
				vertProd = 1
			}
			// horizontal
			if j <= gridSize-serchLen {
				horiProd = horizonatalProd(grid, i, j, serchLen)
			} else {
				horiProd = 1
			}

			if diagProd > maxProd {
				maxProd = diagProd
			}
			if vertProd > maxProd {
				maxProd = vertProd
			}
			if horiProd > maxProd {
				maxProd = horiProd
			}
		}
	}

	return maxProd
}
