package main

import (
	"fmt"
	"strconv"
)

func convertToString(arr string) string {
	b := make([]int, 26)
	for i := 0; i < len(arr); i++ {
		b[arr[i]-'a']++
	}

	str := ""
	for i := 0; i < 26; i++ {
		str += strconv.Itoa(b[i])
		if i != 25 {
			str += "\\0"
		}
	}
	return str
}

func groupAnagrams(strs []string) [][]string {
	m := make(map[string][]string)
	for _, str := range strs {
		str2 := convertToString(str)
		l := m[str2]
		l = append(l, str)
		m[str2] = l
	}

	result := make([][]string, 0, len(m))
	for _, v := range m {
		result = append(result, v)
	}
	return result
}

func main() {
	fmt.Println(groupAnagrams([]string{"eat", "tea", "tan", "ate", "nat", "bat"}))
}
