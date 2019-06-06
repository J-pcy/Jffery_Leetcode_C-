/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n^2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

class Solution {
public:
    /*
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return -1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) return nums[i];
        }
        return -1;
    }
    */
    /*
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return -1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == nums[j]) return nums[i];
            }
        }
        return -1;
    }
    */
    /*
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2.0, cnt = 0;
            for (int num : nums) {
                if (num <= mid) ++cnt;
            }
            if (cnt <= mid) left = mid + 1;
            else right = mid;
        }
        return right;
    }
    */
    /*
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return -1;
        int slow = 0, fast = 0, tmp = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        while (true) {
            slow = nums[slow];
            tmp = nums[tmp];
            if (slow == tmp) break;
        }
        return slow;
    }
    */
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return -1;
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int bit = (1 << i), cnt1 = 0, cnt2 = 0;
            for (int j = 0; j < n; ++j) {
                if ((j & bit) > 0) cnt1++;
                if ((nums[j] & bit) > 0) cnt2++;
            }
            if (cnt2 > cnt1) res += bit;
        }
        return res;
    }
};