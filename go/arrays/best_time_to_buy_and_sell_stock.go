package main

func maxProfit(prices []int) int {
	minSoFar := prices[0]
	maxPr := 0

	for i := 1; i < len(prices); i++ {
		maxPr = max(maxPr, prices[i]-minSoFar)
		minSoFar = min(minSoFar, prices[i])
	}
	return maxPr
}
