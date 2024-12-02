package main

func generate(numRows int) [][]int {
	s := make([][]int, numRows)
	s[0] = []int{1}

	for i := 1; i < numRows; i++ {
		n := i + 1

		l := make([]int, n)
		l[0] = 1
		l[n-1] = 1

		for j := 1; j < n; j++ {
			l[j] = s[i-1][j] + s[i-1][j-1]
		}
		s[i] = l
	}

	return s
}
