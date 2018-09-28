/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if (numerator < 0 ^ denominator < 0) res += "-";
        long long int n = abs((long long) numerator);
        long long int d = abs((long long) denominator);
        res += to_string(n / d);
        long long int rem = n % d;
        if (rem == 0) return res;
        res += ".";
        unordered_map<long long, int> m;
        while (rem) {
            if (m.count(rem)) {
                res.insert(m[rem], "(");
                res += ")";
                return res;
            }
            m[rem] = res.size();
            rem *= 10;
            res += to_string(rem / d);
            rem %= d;
        }
        return res;
    }
};