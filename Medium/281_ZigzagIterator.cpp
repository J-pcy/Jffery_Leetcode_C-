/*
Given two 1d vectors, implement an iterator to return their elements alternately.

Example:

Input:
v1 = [1,2]
v2 = [3,4,5,6] 

Output: [1,3,2,4,5,6]

Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,3,2,4,5,6].
Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question:
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases.
If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example:

Input:
[1,2,3]
[4,5,6,7]
[8,9]

Output: [1,4,8,2,5,9,3,6,7].
*/

class ZigzagIterator {
public:
    /*
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        v.push_back(v1);
        v.push_back(v2);
        i = j = 0;
    }

    int next() {
        return i <= j ? v[0][i++] : v[1][j++];
    }

    bool hasNext() {
        if (i >= v[0].size()) i = INT_MAX;
        if (j >= v[1].size()) j = INT_MAX;
        return i < v[0].size() || j < v[1].size();
    }
private:
    vector<vector<int>> v;
    int i, j;
    */
    /*
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int len1 = v1.size(), len2 = v2.size();
        int len = max(len1, len2);
        for (int i = 0; i < len; ++i) {
            if (i < len1) v.push_back(v1[i]);
            if (i < len2) v.push_back(v2[i]);
        }
    }
    
    int next() {
        return v[index++];
    }
    
    bool hasNext() {
        return index < v.size();
    }
private:
    vector<int> v;
    int index = 0;
    */
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) q.push(make_pair(v1.begin(), v1.end()));
        if (!v2.empty()) q.push(make_pair(v2.begin(), v2.end()));
    }
    
    int next() {
        auto it = q.front().first, end = q.front().second;
        q.pop();
        if (it + 1 != end) q.push(make_pair(it + 1, end));
        return *it;
    }
    
    bool hasNext() {
        return !q.empty();
    }
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */