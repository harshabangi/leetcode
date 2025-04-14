package main

import "fmt"

var arr = [][]int{
	{0, -1}, {0, 1}, {-1, 0}, {1, 0},
}

func existHelper(board [][]rune, word []rune, i, j, m, n int, visited [][]bool, t int) bool {
	if t == len(word) {
		return true
	}

	var result bool

	for k := 0; k < len(arr); k++ {
		p, q := i+arr[k][0], j+arr[k][1]

		if underBoundary(p, q, m, n) && !visited[p][q] && board[p][q] == word[t] {
			visited[p][q] = true
			result = result || existHelper(board, word, p, q, m, n, visited, t+1)
			visited[p][q] = false
		}
	}
	return result
}

func underBoundary(i, j, m, n int) bool {
	return i >= 0 && i < m && j >= 0 && j < n
}

func getVisitedMatrix(m, n int) [][]bool {
	visited := make([][]bool, m)
	for i := 0; i < m; i++ {
		visited[i] = make([]bool, n)
	}
	return visited
}

func exist(board [][]byte, word string) bool {
	r := make([][]rune, len(board))
	for i := 0; i < len(board); i++ {
		r[i] = []rune(string(board[i]))
	}

	wordRunes := []rune(word)
	m := len(r)
	n := len(r[0])

	for i := 0; i < len(r); i++ {
		for j := 0; j < len(r[i]); j++ {
			if r[i][j] == wordRunes[0] {
				visited := getVisitedMatrix(m, n)
				visited[i][j] = true
				if existHelper(r, wordRunes, i, j, m, n, visited, 1) {
					return true
				}
			}
		}
	}

	return false
}

func main() {
	input := []string{"ABCE", "SFES", "ADEE"}

	l := make([][]byte, len(input))
	for i := 0; i < len(input); i++ {
		l[i] = []byte(input[i])
	}
	fmt.Println(exist(l, "ABCESEEEFS"))
}
