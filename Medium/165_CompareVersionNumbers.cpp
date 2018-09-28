/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int i = 0, j = 0, d1 = 0, d2 = 0;
        while (i < n1 || j < n2) {
            string v1, v2;
            while(i < n1 && version1[i] != '.') v1.push_back(version1[i++]);
            while(j < n2 && version2[j] != '.') v2.push_back(version2[j++]);
            d1 = atoi(v1.c_str());
            d2 = atoi(v2.c_str());
            if (d1 < d2) return -1;
            if (d1 > d2) return 1;
            i++; j++;
        }
        return 0;
    }
};