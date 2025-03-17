class Solution {
public:
    int calculate(string s) {
        int n=s.length();

        int currnum=0;

        char prevops='+';
        stack<int>st;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                currnum=currnum*10+(s[i]-'0');
            }

            if(s[i]!=' ' && !isdigit(s[i]) || i==n-1){
                if(prevops=='+'){
                    st.push(currnum);
                }else if(prevops=='-'){
                    st.push(-currnum);
                }else if(prevops=='*'){
                    int x=st.top();
                    st.pop();
                    st.push(x*currnum);
                }else if(prevops=='/'){
                    int x=st.top();
                    st.pop();
                    st.push(x/currnum);
                }

                currnum=0;
                prevops=s[i];
            }
        }

        int res=0;

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

    return res;

    }
};