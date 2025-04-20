package main

import "fmt"

func canPlaceFlowers(flowerbed []int, n int) bool {
	for i := 0; i < len(flowerbed); i++ {
		if flowerbed[i] == 1 || i-1 >= 0 && flowerbed[i-1] == 1 || i+1 < len(flowerbed) && flowerbed[i+1] == 1 {
			continue
		} else {
			flowerbed[i] = 1
			n--
		}
	}
	return n <= 0
}

func main() {
	fmt.Println(canPlaceFlowers([]int{0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0}, 4))
}
