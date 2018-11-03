/*
Implement an iterator to flatten a 2d vector.

Example:

Input: 2d vector =
[
  [1,2],
  [3],
  [4,5,6]
]
Output: [1,2,3,4,5,6]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,2,3,4,5,6].
Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.
*/

/*
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for (auto a: vec2d) {
            v.insert(v.end(), a.begin(), a.end());
        }
    }

    int next() {
        return v[idx++];
    }

    bool hasNext() {
        return idx < v.size();
    }
private:
    vector<int> v;
    int idx = 0;
};
*/
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        v = vec2d;
        x = y = 0;
    }
    int next() {
        return v[x][y++];
    }
    bool hasNext() {
        while (x < v.size() && y == v[x].size()) {
            x++;
            y = 0;
        }
        return x < v.size();
    }
private:
    vector<vector<int>> v;
    int x, y;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */