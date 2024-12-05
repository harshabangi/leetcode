package main

func strStr(haystack string, needle string) int {
	hr := []rune(haystack)
	nr := []rune(needle)

	for start := 0; start <= len(haystack)-len(needle); start++ {
		match := true
		for k, j := start, 0; j < len(nr); k, j = k+1, j+1 {
			if hr[k] != nr[j] {
				match = false
				break
			}
		}
		if match {
			return start
		}
	}

	return -1
}
