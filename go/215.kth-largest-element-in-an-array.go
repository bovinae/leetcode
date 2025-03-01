/*
 * @lc app=leetcode id=215 lang=go
 *
 * [215] Kth Largest Element in an Array
 */

package main

// @lc code=start
func findKthLargest(nums []int, k int) int {
	l, r := 0, len(nums)-1
	for l < r {
		// use last element to partition
		s := l
		t := r
		for l < r {
			for l < r && nums[l] < nums[t] {
				l++
			}
			for l < r && nums[r] >= nums[t] {
				r--
			}
			nums[l], nums[r] = nums[r], nums[l]
		}
		// l == r
		nums[l], nums[t] = nums[t], nums[l]
		if t-l+1 == k {
			return nums[l]
		}
		if t-l+1 > k {
			l++
			r = t
		} else {
			k -= t - l + 1
			l = s
			r--
		}
	}
	// l == r
	return nums[l]
}

// @lc code=end

func main() {
	findKthLargest([]int{3, 2, 3, 1, 2, 4, 5, 5, 6, 7, 7, 8, 2, 3, 1, 1, 1, 10, 11, 5, 6, 2, 4, 7, 8, 5, 6}, 2)
}

/*
[3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6]
[3,2,3,1,2,4,5,5,5,4,2,5,2,3,1,1,1,6,  11,8,6,7,7,7,8,6,10] 6,8,6,7,7,7,8,11,10
[3,2,3,1,2,4,5,5,5,4,2,5,2,3,1,1,1,6,  6,8,6,7,7,7,10,11,8]
*/
