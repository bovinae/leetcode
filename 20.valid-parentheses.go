package main

import "fmt"

/*
 * @lc app=leetcode id=20 lang=golang
 *
 * [20] Valid Parentheses
 */

// @lc code=start
func isValid(s string) bool {
	var a, b, c int
	for _, v := range s {
		switch v {
		case '(':
			a++
		case '[':
			b++
		case '{':
			c++
		case ')':
			a--
		case ']':
			b--
		case '}':
			c--
		}
		if a < 0 || b < 0 || c < 0 {
			return false
		}
	}
	return a == 0 && b == 0 && c == 0
}

// @lc code=end

func main() {
	fmt.Println(isValid("([])"))
}
