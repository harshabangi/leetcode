package main

func hasDuplicatesInHorizontalAndVerticalRows(x, y int, board [][]byte) bool {
	value := board[x][y]

	for y1 := y + 1; y1 < 9; y1++ {
		if board[x][y1] == value {
			return true
		}
	}
	for y1 := y - 1; y1 >= 0; y1-- {
		if board[x][y1] == value {
			return true
		}
	}

	for x1 := x + 1; x1 < 9; x1++ {
		if board[x1][y] == value {
			return true
		}
	}
	for x1 := x - 1; x1 >= 0; x1-- {
		if board[x1][y] == value {
			return true
		}
	}
	return false
}

func isValidSudoku(board [][]byte) bool {
	rowsMap := make([]map[byte]struct{}, 9)
	colsMap := make([]map[byte]struct{}, 9)
	boxMap := make([]map[byte]struct{}, 9)

	for i := 0; i < 9; i++ {
		rowsMap[i] = make(map[byte]struct{}, 9)
		colsMap[i] = make(map[byte]struct{}, 9)
		boxMap[i] = make(map[byte]struct{}, 9)
	}

	for row := 0; row < 9; row++ {
		for col := 0; col < 9; col++ {
			data := board[row][col]
			if data != '.' {
				v := rowsMap[row]
				if _, ok := v[data]; ok {
					return false
				} else {
					v[data] = struct{}{}
				}

				v2 := colsMap[col]
				if _, ok := v2[data]; ok {
					return false
				} else {
					v2[data] = struct{}{}
				}

				box := (row/3)*3 + col/3
				v3 := boxMap[box]
				if _, ok := v3[data]; ok {
					return false
				} else {
					v3[data] = struct{}{}
				}
			}
		}
	}
	return true
}

func isValidSudoku2(board [][]byte) bool {
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if board[i][j] != '.' {
				if hasDuplicatesInHorizontalAndVerticalRows(i, j, board) {
					return false
				}

				for m1 := 0; m1 < 3; m1++ {
					for n1 := 0; n1 < 3; n1++ {
						m := make(map[byte]struct{})

						for p := 3 * m1; p < 3*m1+3; p++ {
							for q := 3 * n1; q < 3*n1+3; q++ {
								if board[p][q] != byte('.') {
									if _, ok := m[board[p][q]]; ok {
										return false
									} else {
										m[board[p][q]] = struct{}{}
									}
								}
							}
						}

					}
				}
			}
		}
	}
	return true
}

func main() {
}
