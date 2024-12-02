package main

type key struct {
	l int
	m int
}

func setZeroes(matrix [][]int) {

	m := len(matrix)
	n := len(matrix[0])
	mp := make(map[key]struct{})

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if matrix[i][j] == 0 {
				mp[key{l: i, m: j}] = struct{}{}
			}
		}
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {

			ky := key{l: i, m: j}
			_, ok := mp[ky]

			if matrix[i][j] == 0 && ok {

				for k1 := i; k1 >= 0; k1-- {
					matrix[k1][j] = 0
				}

				for k1 := i; k1 < m; k1++ {
					matrix[k1][j] = 0
				}

				for k1 := j; k1 < n; k1++ {
					matrix[i][k1] = 0
				}

				for k1 := j; k1 >= 0; k1-- {
					matrix[i][k1] = 0
				}
			}
		}
	}
}

func main() {

}
