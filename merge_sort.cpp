#include "leetcode.h"

void Print(string prefix, vector<int>& nums, int l, int r) {
    cout << prefix << ": ";
    for (int i = l; i < r; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void merge(vector<int>& nums, int l, int r) {
    Print("merge before", nums, l, r);
    int m = (l + r) / 2;
    int left = l, right = m;
    vector<int> tmp;
    while (left < m && right < r) {
        if (nums[left] > nums[right]) {
            tmp.push_back(nums[right]);
            right++;
        } else {
            tmp.push_back(nums[left]);
            left++;
        }
    }
    while (left < m) {
        tmp.push_back(nums[left++]);
    }
    while (right < r) {
        tmp.push_back(nums[right++]);
    }
    Print("tmp", tmp, 0, tmp.size());
    for (int i = l; i < r; i++) {
        nums[i] = tmp[i-l];
    }
    Print("merge after", nums, l, r);
}

void merge_sort(vector<int>& nums, int l, int r) {
    if (r - l < 2) {
        return ;
    }
    if (r - l == 2) {
        if (nums[l] > nums[r-1]) swap(nums[l], nums[r-1]);
        return ;
    }
    int m = (l + r) / 2;
    Print("merge_sort left", nums, l, m);
    merge_sort(nums, l, m);
    Print("merge_sort right", nums, m, r);
    merge_sort(nums, m, r);
    merge(nums, l, r);
}

int main() {
    vector<int> nums{3, 1, 2, 9, 7, 5, 0, 6};
    merge_sort(nums, 0, nums.size());
    for (auto &&i : nums) {
        cout << i << " ";
    }
    cout << endl;
}
