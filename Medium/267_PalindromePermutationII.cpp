/*
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

Example 1:

Input: "aabb"
Output: ["abba", "baab"]
Example 2:

Input: "abc"
Output: []
*/

class Solution {
public:
/*
    vector<string> generatePalindromes(string s) {
        unordered_set<string> res;
        unordered_map<char, int> m;
        string t = "", mid = "";
        for (auto a: s) ++m[a];
        for (auto a: m) {
            if (a.second % 2 == 1) mid += a.first;
            t += string(a.second / 2, a.first);
            if (mid.size() > 1) return {};
        }
        permute(t, 0, mid, res);
        return vector<string>(res.begin(), res.end());
    }
private:
    void permute(string &t, int start, string mid, unordered_set<string>& res) {
        if (start >= t.size()) {
            res.insert(t + mid + string(t.rbegin(), t.rend()));
        }
        for (int i = start; i < t.size(); ++i) {
            if (i != start && t[i] == t[start]) continue;
            swap(t[start], t[i]);
            permute(t, start + 1, mid, res);
            swap(t[start], t[i]);
        }
    }*/
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> m;
        string t = "", mid = "";
        for (auto a : s) ++m[a];
        for (auto &it : m) {
            if (it.second % 2 == 1) mid += it.first;
            it.second /= 2;
            t += string(it.second, it.first);
            if (mid.size() > 1) return {};
        }
        permute(t, m, mid, "", res);
        return res;
    }
    void permute(string &t, unordered_map<char, int> &m, string mid, string out, vector<string> &res) {
        if (out.size() >= t.size()) {
            res.push_back(out + mid + string(out.rbegin(), out.rend()));
            return;
        } 
        for (auto &it : m) {
            if (it.second > 0) {
                --it.second;
                permute(t, m, mid, out + it.first, res);
                ++it.second;
            }
        }
    }
};