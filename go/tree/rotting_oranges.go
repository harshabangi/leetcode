package main

import "fmt"

type Queue[T any] struct {
	data []T
}

func (q *Queue[T]) Empty() bool {
	return q.Len() == 0
}

func (q *Queue[T]) Len() int {
	return len(q.data)
}

func (q *Queue[T]) Push(inp T) {
	q.data = append(q.data, inp)
}

func (q *Queue[T]) Pop() T {
	if q.Len() == 0 {
		panic("queue is empty")
	}
	e := q.data[0]
	q.data = q.data[1:]
	return e
}

func (q *Queue[T]) Front() T {
	if q.Len() == 0 {
		panic("queue is empty")
	}
	return q.data[0]
}

type cell struct {
	x int
	y int
}

func underBoundary(x, y, m, n int) bool {
	return x >= 0 && x < m && y >= 0 && y < n
}

func orangesRotting(grid [][]int) int {
	m := len(grid)
	n := len(grid[0])

	q := Queue[cell]{}
	visited := make(map[cell]struct{})

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 2 {
				c := cell{x: i, y: j}
				q.Push(c)
				visited[c] = struct{}{}
			}
		}
	}

	ans := 0
	directions := [][]int{
		{1, 0},
		{-1, 0},
		{0, 1},
		{0, -1},
	}

	for !q.Empty() {
		size := q.Len()

		for i := 0; i < size; i++ {
			t := q.Pop()

			for j := 0; j < len(directions); j++ {
				x, y := t.x+directions[j][0], t.y+directions[j][1]
				if underBoundary(x, y, m, n) && grid[x][y] == 1 {
					q.Push(cell{x, y})
					grid[x][y] = 2
				}
			}
		}
		ans++
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				return -1
			}
		}
	}
	if ans == 0 {
		return ans
	}
	return ans - 1
}

func main() {
	fmt.Println(orangesRotting([][]int{{0, 2}}))
}
