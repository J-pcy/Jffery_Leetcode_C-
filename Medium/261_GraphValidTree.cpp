/*
Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
*/

class Solution {
public:
/*
    //Memory Limit Exceeded
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> g(n, vector<int>());
        vector<bool> v(n, false);
        for (auto a: edges) {
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
        }
        if (!dfs(g, v, 0, -1)) return false;
        for (auto a: v) {
            if (!a) return false;
        }
        return true;
    }
    bool dfs(vector<vector<int>> g, vector<bool>& v, int cur, int pre) {
        if (v[cur]) return false;
        v[cur] = true;
        for (auto a: g[cur]) {
            if (a != pre) {
                if (!dfs(g, v, a, cur)) return false;
            }
        }
        return true;
    }*/
/*
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> g(n, unordered_set<int>());
        unordered_set<int> s{{0}};
        queue<int> q{{0}};
        for (auto a: edges) {
            g[a.first].insert(a.second);
            g[a.second].insert(a.first);
        }
        while (!q.empty()) {
            int tmp = q.front(); q.pop();
            for (auto a: g[tmp]) {
                if (s.count(a)) return false;
                s.insert(a);
                q.push(a);
                g[a].erase(tmp);
            }
        }
        return s.size() == n;
    }*/
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n, -1);
        for (auto a : edges) {
            int x = find(roots, a.first), y = find(roots, a.second);
            if (x == y) return false;
            roots[x] = y;
        }
        return edges.size() == n - 1;
    }
    int find(vector<int> &roots, int i) {
        while (roots[i] != -1) i = roots[i];
        return i;
    }
};