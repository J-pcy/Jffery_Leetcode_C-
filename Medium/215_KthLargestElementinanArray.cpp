/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

class Solution {
public:
/*
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }*/
/*
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            q.pop();
        }
        return q.top();
    }*/
    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums, 0, nums.size() - 1, k);
    }
private:
    int quickSort(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];
        int start = left, end = right;
        int pivot = nums[start + (end - start) / 2];
        while (start <= end) {
            while (start <= end && nums[start] > pivot) start++;
            while (start <= end && nums[end] < pivot) end--;
            if (start <= end) swap(nums[start++], nums[end--]);
        }
        if (left + k - 1 <= end) return quickSort(nums, left, end, k);
        else if (left + k - 1 >= start) return quickSort(nums, start, right, k - start + left);
        else return nums[end + 1];
    }
};