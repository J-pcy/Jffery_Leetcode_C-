/*
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res, set;
        for (int i = 0; i + 9 < s.size(); i++) {
            string tmp = s.substr(i, 10);
            if (set.count(tmp)) res.insert(tmp);
            else set.insert(tmp);
        }
        return vector<string>{res.begin(), res.end()};
    }
};
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res, set;
        for (int i = 0; i + 9 < s.size(); i++) {
            string tmp = s.substr(i, 10);
            if (set.count(tmp)) res.insert(tmp);
            else set.insert(tmp);
        }
        return vector<string>{res.begin(), res.end()};
    }
};