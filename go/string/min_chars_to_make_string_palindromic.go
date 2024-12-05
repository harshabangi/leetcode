package main

import (
	"fmt"
	"math"
)

func solve(A string) int {
	sr := []rune(A)
	n := len(sr)

	i := 0
	fr := false

	if n%2 == 0 {
		i = n/2 - 1
	} else {
		fr = true
		i = n / 2
	}

	j, k := 0, 0
	mnLen := math.MaxInt

	for ; i >= 0; i-- {
		b := false
		for j, k = i-1, i+1; j >= 0 && k < n; j, k = j-1, k+1 {
			if sr[j] != sr[k] {
				b = true
				break
			}
		}

		if !b {
			mnLen = min(mnLen, n-k)
		}

		if fr {
			fr = false
			continue
		}

		b = false
		for j, k = i, i+1; j >= 0 && k < n; j, k = j-1, k+1 {
			if sr[j] != sr[k] {
				b = true
				break
			}
		}
		if !b {
			mnLen = min(mnLen, n-k)
		}

	}
	return mnLen
}

func main() {
	fmt.Println(solve("xgg"))
}
