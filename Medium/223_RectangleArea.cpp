/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
Note:

Assume that the total area is never beyond the maximum possible value of int.
*/

class Solution {
public:
/*
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum = (C - A) * (D - B) + (G - E) * (H - F);
        if (G <= A || E >= C || H <= B || F >= D) return sum;
        return sum - (min(G, C) - max(E, A)) * (min(D, H) - max(B, F));
    }*/
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (C - A) * (D - B) + (G - E) * (H - F) - max((long long)min(G, C) - (long long)max(E, A), (long long)0) * max((long long)min(D, H) - (long long)max(B, F), (long long)0);
    }
};