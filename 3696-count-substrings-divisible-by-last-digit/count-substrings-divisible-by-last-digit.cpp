class Solution {
public:
    long long countSubstrings(string s) {
        int n = s.size();
        long long ans = 0;
        
        // We'll maintain DP states for candidate divisors 1 through 9.
        // For candidate i, the inner vector has size i (to store remainders 0..i-1).
        vector<vector<long long>> prev(10), curr(10);
        for (int i = 1; i <= 9; i++) {
            prev[i].assign(i, 0LL);
            curr[i].assign(i, 0LL);
        }
        
        for (int index = 0; index < n; index++) {
            int x = s[index] - '0';
            
            // Clear the current DP state for all candidate divisors.
            for (int i = 1; i <= 9; i++) {
                fill(curr[i].begin(), curr[i].end(), 0LL);
            }
            
            // Extend all substrings ending at the previous index.
            for (int i = 1; i <= 9; i++) {
                for (int r = 0; r < i; r++) {
                    long long cnt = prev[i][r];
                    if (cnt > 0) {
                        int new_r = (r * 10 + x) % i;
                        curr[i][new_r] += cnt;
                    }
                }
            }
            
            // Start new substrings at the current index.
            // For every candidate divisor i (from 1 to 9), the new substring has value x,
            // so its remainder modulo i is (x % i).
            for (int i = 1; i <= 9; i++) {
                int r = x % i;  // note: if x is 0, r is 0.
                curr[i][r] += 1;
            }
            
            // If the current digit (which becomes the last digit of substrings ending here)
            // is nonzero, then only the substrings computed for candidate divisor equal to x
            // can be valid (they satisfy "divisible by last digit").
            if (x != 0) {
                ans += curr[x][0];
            }
            
            // Prepare for next iteration: move current state to previous.
            prev = curr;
        }
        
        return ans;
    }
};
