package main

import (
	"fmt"
)

func underBoundary(m, n, i, j int) bool {
	return i >= 0 && i < m && j >= 0 && j < n
}

func spiralOrder(matrix [][]int) []int {
	m := len(matrix)
	n := len(matrix[0])

	visited := make([][]bool, m)
	for i := 0; i < m; i++ {
		visited[i] = make([]bool, n)
	}

	result := make([]int, 0, m*n)
	direction := "W"
	count, i, j := 0, 0, 0

	for {
		if count == m*n {
			break
		}

		switch direction {
		case "W":
			if underBoundary(m, n, i, j) && !visited[i][j] {
				count++
				visited[i][j] = true
				result = append(result, matrix[i][j])
				j++
			} else {
				direction = "S"
				i++
				j--
			}
		case "S":
			if underBoundary(m, n, i, j) && !visited[i][j] {
				count++
				visited[i][j] = true
				result = append(result, matrix[i][j])
				i++
			} else {
				direction = "E"
				i--
				j--
			}
		case "E":
			if underBoundary(m, n, i, j) && !visited[i][j] {
				count++
				visited[i][j] = true
				result = append(result, matrix[i][j])
				j--
			} else {
				direction = "N"
				i--
				j++
			}
		default:
			if underBoundary(m, n, i, j) && !visited[i][j] {
				count++
				visited[i][j] = true
				result = append(result, matrix[i][j])
				i--
			} else {
				direction = "W"
				i++
				j++
			}
		}

	}

	return result
}

func main() {
	fmt.Println(spiralOrder([][]int{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}))
}
