package main

import "fmt"

type dp struct {
	top    [][]int
	bottom [][]int
	left   [][]int
	right  [][]int
	data   [][]int
}

func initialize2dSlice(n int, value int) [][]int {
	arr := make([][]int, n)
	for i := 0; i < n; i++ {
		a := make([]int, n)
		for j := 0; j < n; j++ {
			a[j] = value
		}
		arr[i] = a
	}
	return arr
}

func underBoundary(x, y, n int) bool {
	return x >= 0 && x < n && y >= 0 && y < n
}

func traverse(x, y, n int, dp *dp) int {
	if dp.data[x][y] == 0 {
		return 0
	}
	top := traverseTop(x-1, y, n, dp)
	bottom := traverseBottom(x+1, y, n, dp)
	left := traverseLeft(x, y-1, n, dp)
	right := traverseRight(x, y+1, n, dp)
	return 1 + min(top, min(bottom, min(left, right)))
}

func traverseTop(x, y, n int, dp *dp) int {
	if !underBoundary(x, y, n) {
		return 0
	}
	if dp.data[x][y] == 0 {
		return 0
	}
	if dp.top[x][y] != -1 {
		return dp.top[x][y]
	}
	dp.top[x][y] = 1 + traverseTop(x-1, y, n, dp)
	return dp.top[x][y]
}

func traverseBottom(x, y, n int, dp *dp) int {
	if !underBoundary(x, y, n) {
		return 0
	}
	if dp.data[x][y] == 0 {
		return 0
	}
	if dp.bottom[x][y] != -1 {
		return dp.bottom[x][y]
	}
	dp.bottom[x][y] = 1 + traverseBottom(x+1, y, n, dp)
	return dp.bottom[x][y]
}

func traverseLeft(x, y, n int, dp *dp) int {
	if !underBoundary(x, y, n) {
		return 0
	}
	if dp.data[x][y] == 0 {
		return 0
	}
	if dp.left[x][y] != -1 {
		return dp.left[x][y]
	}
	dp.left[x][y] = 1 + traverseLeft(x, y-1, n, dp)
	return dp.left[x][y]
}

func traverseRight(x, y, n int, dp *dp) int {
	if !underBoundary(x, y, n) {
		return 0
	}
	if dp.data[x][y] == 0 {
		return 0
	}
	if dp.right[x][y] != -1 {
		return dp.right[x][y]
	}
	dp.right[x][y] = 1 + traverseRight(x, y+1, n, dp)
	return dp.right[x][y]
}

func orderOfLargestPlusSign(n int, mines [][]int) int {
	d := &dp{
		top:    initialize2dSlice(n, -1),
		bottom: initialize2dSlice(n, -1),
		left:   initialize2dSlice(n, -1),
		right:  initialize2dSlice(n, -1),
		data:   initialize2dSlice(n, 1),
	}

	for i := 0; i < len(mines); i++ {
		d.data[mines[i][0]][mines[i][1]] = 0
	}

	mx := 0

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			mx = max(mx, traverse(i, j, n, d))
		}
	}

	return mx
}

func main() {
	fmt.Println(orderOfLargestPlusSign(5, [][]int{{0, 0}}))
}
