
class Solution {
public:
    int solve(const string& s, int& i) { 
        int res = 0;
        int sign = 1; 
        int number = 0;

        while (i < s.size()) {
            char c = s[i];
            if (c == '+') {
                res += sign * number;
                number = 0;
                sign = 1;
            } else if (c == '-') {
                res += sign * number;
                number = 0;
                sign = -1; 
            } else if (isdigit(c)) {
                number = number * 10 + (c - '0'); 
            } else if (c == '(') {
                i++; 
                number = solve(s, i); 
            } else if (c == ')') {
                res += sign * number; 
                return res; 
            }
            i++; 
        }
        res += sign * number; 
        return res;
    }

    int calculate(string s) {
        int i = 0; 
        return solve(s, i);
    }
};

