package main

func underBoundary2(x, y, m, n int) bool {
	return x >= 0 && x < m && y >= 0 && y < n
}

func doCount(x, y, m, n int, board [][]int) int {
	sum := 0
	if underBoundary2(x-1, y-1, m, n) && (board[x-1][y-1] == 1 || board[x-1][y-1] == 10 || board[x-1][y-1] == 11) {
		sum++
	}
	if underBoundary2(x-1, y, m, n) && (board[x-1][y] == 1 || board[x-1][y] == 10 || board[x-1][y] == 11) {
		sum++
	}
	if underBoundary2(x-1, y+1, m, n) && (board[x-1][y+1] == 1 || board[x-1][y+1] == 10 || board[x-1][y+1] == 11) {
		sum++
	}
	if underBoundary2(x, y-1, m, n) && (board[x][y-1] == 1 || board[x][y-1] == 10 || board[x][y-1] == 11) {
		sum++
	}
	if underBoundary2(x, y+1, m, n) && (board[x][y+1] == 1 || board[x][y+1] == 10 || board[x][y+1] == 11) {
		sum++
	}
	if underBoundary2(x+1, y-1, m, n) && (board[x+1][y-1] == 1 || board[x+1][y-1] == 10 || board[x+1][y-1] == 11) {
		sum++
	}
	if underBoundary2(x+1, y, m, n) && (board[x+1][y] == 1 || board[x+1][y] == 10 || board[x+1][y] == 11) {
		sum++
	}
	if underBoundary2(x+1, y+1, m, n) && (board[x+1][y+1] == 1 || board[x+1][y+1] == 10 || board[x+1][y+1] == 11) {
		sum++
	}

	if (board[x][y] == 1 || board[x][y] == 10 || board[x][y] == 11) && sum < 2 {
		return 10
	}
	if (board[x][y] == 1 || board[x][y] == 10 || board[x][y] == 11) && (sum == 2 || sum == 3) {
		return 11
	}
	if (board[x][y] == 1 || board[x][y] == 10 || board[x][y] == 11) && (sum > 3) {
		return 10
	}
	if (board[x][y] == 0 || board[x][y] == 8 || board[x][y] == 9) && (sum == 3) {
		return 9
	}
	return 8
}

func gameOfLife(board [][]int) {
	p := len(board)
	q := len(board[0])

	for i := 0; i < p; i++ {
		for j := 0; j < q; j++ {
			board[i][j] = doCount(i, j, p, q, board)
		}
	}
	for i := 0; i < p; i++ {
		for j := 0; j < q; j++ {
			if board[i][j] == 8 {
				board[i][j] = 0
			} else if board[i][j] == 9 {
				board[i][j] = 1
			} else if board[i][j] == 10 {
				board[i][j] = 0
			} else if board[i][j] == 11 {
				board[i][j] = 1
			}
		}
	}
}
