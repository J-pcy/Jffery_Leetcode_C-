/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/

class Solution {
public:
/*
    int calculate(string s) {
        int res = 0, num = 0;
        char oper = '+';
        stack<int> stack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            }
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == s.size() - 1) {
                if (oper == '+') stack.push(num);
                if (oper == '-') stack.push(-num);
                if (oper == '*') {
                    int tmp = stack.top(); stack.pop();
                    stack.push(tmp * num);
                }
                if (oper == '/') {
                    int tmp = stack.top(); stack.pop();
                    stack.push(tmp / num);
                }
                oper = s[i];
                num = 0;
            }
        }
        while (!stack.empty()) {
            res += stack.top();
            stack.pop();
        }
        return res;
    }*/
    int calculate(string s) {
        int res = 0, num = 0, cur = 0;
        char oper = '+';
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') num = num * 10 + s[i] - '0';
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == s.size() - 1) {
                switch (oper) {
                    case '+' : cur += num; break;
                    case '-' : cur -= num; break;
                    case '*' : cur *= num; break;
                    case '/' : cur /= num; break;
                }
                if (s[i] == '+' || s[i] == '-' || i == s.size() - 1) {
                    res += cur;
                    cur = 0;
                }
                oper = s[i];
                num = 0;
            }
        }
        return res;
    }
};