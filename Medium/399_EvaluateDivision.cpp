/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res(queries.size(), -1);
        unordered_set<string> s;
        for (auto equation: equations) {
            s.insert(equation.first);
            s.insert(equation.second);
        }
        for (int i = 0; i < queries.size(); i++) {
            vector<string> query{queries[i].first, queries[i].second};
            if (s.count(query[0]) && s.count(query[1])) {
                vector<int> v;
                res[i] = helper(equations, values, query, v);
            }
        }
        return res;
    }
private:
    double helper(vector<pair<string, string>> equations, vector<double>& values, vector<string> query, vector<int>& v) {
        for (int i = 0; i < equations.size(); i++) {
            if (query[0] == equations[i].first && query[1] == equations[i].second) {
                return values[i];
            }
            if (query[1] == equations[i].first && query[0] == equations[i].second) {
                return 1.0 / values[i];
            }
            if (find(v.begin(), v.end(), i) == v.end() && query[0] == equations[i].first) {
                v.push_back(i);
                double tmp = helper(equations, values, {equations[i].second, query[1]}, v) * values[i];
                if (tmp > 0) {
                    return tmp;
                } else {
                    v.pop_back();
                }
            }
            if (find(v.begin(), v.end(), i) == v.end() && query[0] == equations[i].second) {
                v.push_back(i);
                double tmp = helper(equations, values, {equations[i].first, query[1]}, v) / values[i];
                if (tmp > 0) {
                    return tmp;
                } else {
                    v.pop_back();
                }
            }
        }
        return -1.0;
    }
};