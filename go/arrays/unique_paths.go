package main

func uniquePaths(m int, n int) int {
	dp := make([][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
		for j := 0; j < n; j++ {
			dp[i][j] = -1
		}
	}
	return uniquePathsHelper(m, n, 0, 0, dp)
}

func uniquePathsHelper(m, n, x, y int, dp [][]int) int {
	if x < 0 || x >= m || y < 0 || y >= n {
		return 0
	}
	if dp[x][y] != -1 {
		return dp[x][y]
	}
	if x == m-1 && y == n-1 {
		return 1
	}
	dp[x][y] = uniquePathsHelper(m, n, x+1, y, dp) + uniquePathsHelper(m, n, x, y+1, dp)
	return dp[x][y]
}
