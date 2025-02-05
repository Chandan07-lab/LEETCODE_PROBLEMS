class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n1 = s1.length();

    if (s1 == s2) {
        return true;
    }

    int diffs = 0;
    int firstindex = 0, secondindex = 0;

    for (int i = 0; i < n1; i++) {
        if (s1[i] != s2[i]) {
            diffs++;

            if (diffs > 2) {
                return false; 
            } 
            else if (diffs == 1) {
                firstindex = i;
            } 
            else {
                secondindex = i;
            }
        }
    }

    return s1[firstindex] == s2[secondindex] && s1[secondindex] == s2[firstindex];
    }
};