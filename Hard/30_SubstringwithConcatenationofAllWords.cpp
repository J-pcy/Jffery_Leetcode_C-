/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input:
  s = "wordgoodstudentgoodword",
  words = ["word","student"]
Output: []
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) {
            return res;
        }
        int n = words.size(), m = words[0].size();
        unordered_map<string, int> m1;
        for (auto &word: words) {
            m1[word]++;
        }
        for (int i = 0; i <= (int)s.size() - m * n; i++) {
            unordered_map<string, int> m2;
            int j = 0;
            for (j = 0; j < n; j++) {
                string tmp = s.substr(i + j * m, m);
                if (m1.find(tmp) == m1.end()) break;
                ++m2[tmp];
                if (m2[tmp] > m1[tmp]) break;
            }
            if (j == n) {
                res.push_back(i);
            }
        }
        return res;
    }
};