class Solution {
public:
    string fractionAddition(string expr) {
        int nu = 0; // numerator of the resulting fraction
        int d = 1;  // denominator of the resulting fraction

        int i = 0;
        int n = expr.length();
        
        while (i < n) {
            int cn = 0; // current numerator
            int cd = 0; // current denominator
            bool isn = (expr[i] == '-'); // check if the current fraction is negative

            if (expr[i] == '+' || expr[i] == '-') {
                i++;
            }

            // Build the current numerator (cn)
            while (i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                cn = (cn * 10) + val;
                i++;
            }

            i++; // skip the division character '/'

            if (isn == true) {
                cn *= -1;
            }

            // Build the current denominator (cd)
            while (i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                cd = (cd * 10) + val;
                i++;
            }

            // Combine the fractions
            nu = nu * cd + cn * d;
            d = d * cd;
        }

        // Simplify the resulting fraction
        int g = abs(__gcd(nu, d));
        nu /= g;
        d /= g;

        return to_string(nu) + "/" + to_string(d);
    }
};
