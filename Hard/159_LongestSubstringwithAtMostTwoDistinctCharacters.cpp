/*
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
*/

class Solution {
public:
/*
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            ++m[s[i]];
            while (m.size() > 2) {
                if (--m[s[left]] == 0) {
                    m.erase(s[left]);
                }
                left++;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }*/
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]] = i;
            while (m.size() > 2) {
                if (m[s[left]] == left) {
                    m.erase(s[left]);
                }
                left++;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};