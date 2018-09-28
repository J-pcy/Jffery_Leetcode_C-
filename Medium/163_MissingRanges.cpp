/*
Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]
*/

class Solution {
public:
/*
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long int tmp;
        if (nums.size() == 0) {
            tmp = (long int)upper - (long int)lower;
            if (tmp >= 2) res.push_back(to_string(lower) + "->" + to_string(upper));
            else res.push_back(to_string(lower));
            return res;
        }
        tmp = (long int)nums[0] - (long int)lower;
        if (tmp >= 2) res.push_back(to_string(lower) + "->" + to_string(nums[0] - 1));
        else if (tmp == 1) res.push_back(to_string(lower));
        for (int i = 1; i < nums.size(); i++) {
            tmp = (long int)nums[i] - (long int)nums[i - 1];
            if (tmp > 2) res.push_back(to_string(nums[i - 1] + 1) + "->" + to_string(nums[i] - 1));
            else if (tmp == 2) res.push_back(to_string(nums[i - 1] + 1));
        }
        tmp = (long int)upper - (long int)nums[nums.size() - 1];
        if (tmp >= 2) res.push_back(to_string(nums[nums.size() - 1] + 1) + "->" + to_string(upper));
        else if (tmp == 1) res.push_back(to_string(nums[nums.size() - 1] + 1));
        return res;
    }*/
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long int l = lower;
        for (int i = 0; i <= nums.size(); ++i) {
            long int r = (i < nums.size() && nums[i] <= upper) ? nums[i] : (long int)upper + 1;
            if (l == r) ++l;
            else if (r > l) {
                res.push_back(r - l == 1 ? to_string(l) : to_string(l) + "->" + to_string(r - 1));
                l = r + 1;
            }
        }
        return res;
    }
};