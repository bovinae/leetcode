// "a5.33" 返回""
// "05" 返回 ""
// "36"返回"36"

// "-2.600" 返回 "-2.6"
// "100" 返回 "100"
// "-0.600" 返回 "-0.6"
// "-1." 返回 ""
// ".1" 返回 ""

package main

import "fmt"

func main() {
	// fmt.Println("out:", process("a5.33"))
	// fmt.Println("out:", process("05"))
	// fmt.Println("out:", process("36"))
	// fmt.Println("out:", process("-2.600"))
	// fmt.Println("out:", process("100"))
	// fmt.Println("out:", process("-0.600"))
	// fmt.Println("out:", process("-1."))
	// fmt.Println("out:", process(".1"))
	// fmt.Println("out:", process("1.00"))
	// fmt.Println("out:", process("-.3"))
	// fmt.Println("out:", process("-05"))
	// fmt.Println("out:", process("0.3"))
	// fmt.Println("out:", process("00"))
	// fmt.Println("out:", process("-00"))
	// fmt.Println("out:", process("-0.3"))
	fmt.Println("out:", process("0"))
	fmt.Println("out:", process("9"))
}

func process(a string) string {
	fmt.Println("in:", a)
	dot := false
	for i, v := range a {
		if i == 0 {
			if !digital(v) && v != '-' {
				return ""
			}
			continue
		}
		if digital(v) {
			continue
		}
		if v != '.' {
			return ""
		}
		if dot {
			return ""
		}
		if a[i-1] == '-' {
			return ""
		}
		dot = true
	}
	if !dot {
		if a[0] == '-' && a[1] == '0' {
			return ""
		}
		if a[0] == '0' {
			return ""
		}
		return a
	}
	if a[len(a)-1] == '.' {
		return ""
	}
	i := len(a) - 1
	for ; i >= 0; i-- {
		if a[i] == '0' {
			continue
		}
		break
	}
	if a[i] == '.' {
		i++
	}
	return a[:i+1]
}

func digital(r rune) bool {
	return r >= '0' && r < '9'
}
func nonzeroDigital(r rune) bool {
	return r > '0' && r < '9'
}
