package main

import (
	"fmt"
)

func reverseSlice[T rune](inp []T) []T {
	for i, j := 0, len(inp)-1; i < j; i, j = i+1, j-1 {
		t := inp[i]
		inp[i] = inp[j]
		inp[j] = t
	}
	return inp
}

func reverseWords(s string) string {
	var (
		start, end   = 0, len(s) - 1
		sliceOfRunes = []rune(s)
		length       = len(sliceOfRunes)
		emptyRune    = false

		interSlice  []rune
		resultSlice []rune
	)

	for ; start < length && sliceOfRunes[start] == ' '; start++ {
	}

	for ; end >= 0 && sliceOfRunes[end] == ' '; end-- {
	}

	for i := end; i >= start; i-- {
		if sliceOfRunes[i] == ' ' {
			if emptyRune {
				continue
			}
			emptyRune = true
			resultSlice = append(resultSlice, reverseSlice(interSlice)...)
			resultSlice = append(resultSlice, ' ')
			interSlice = []rune{}
		} else {
			emptyRune = false
			interSlice = append(interSlice, sliceOfRunes[i])
		}
	}

	if len(interSlice) > 0 {
		resultSlice = append(resultSlice, reverseSlice(interSlice)...)
	}

	return string(resultSlice)
}

func main() {
	fmt.Println(reverseWords("a good   example"))
}
