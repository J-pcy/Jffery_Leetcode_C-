/*
Given an input string , reverse the string word by word. 

Example:

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Note: 

A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces.
The words are always separated by a single space.
Follow up: Could you do it in-place without allocating extra space?
*/

class Solution {
public:
    void reverseWords(vector<char>& str) {
        int left = 0, right = 0;
        for (int i = 0; i <= str.size(); i++) {
            if (i == str.size() || str[i] == ' ') {
                right = i;
                reverse(str.begin() + left, str.begin() + right);
                left = right + 1;
            }
        }
        reverse(str.begin(), str.end());
    }
};