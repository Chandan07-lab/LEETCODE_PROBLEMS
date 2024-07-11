class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<int> openbracket;
        vector<int>door(n);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
              openbracket.push(i);  
            }else if(s[i]==')'){
                int j=openbracket.top();
                openbracket.pop();
                door[i]=j;
                door[j]=i;
            }
        }
        string result;
        int direction =1;
        for(int i=0;i<n;i+=direction){
            if(s[i]=='('||s[i]==')'){
                i=door[i];
                direction=-direction;
            }else{
                result+=s[i];
            }

        }
        return result;
    }
};
//o(n*n)
// string reverseParentheses(string s) {
//         stack<int> openeBracket; //You can use a vector also as stack
//         string result;
//         for (char currentChar : s) {
//             if (currentChar == '(') {
//                 openeBracket.push(result.length());
//             } else if (currentChar == ')') {
//                 int start = openeBracket.top();
//                 openeBracket.pop();
//                 reverse(result.begin() + start, result.end());
//             } else {
//                 result += currentChar;
//             }
//         }
//         return result;
//     }
// };
