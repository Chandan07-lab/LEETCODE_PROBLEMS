class Solution {
public:
    int minLength(string s) {
        int n=s.length();
        // stack<int>st;
        // for(int i=0;i<n;i++){
        //     char currchar=s[i];
        //     if(st.empty()){
        //         st.push(currchar);
        //         continue;
        //     }
            

        //     if(currchar=='B'&& st.top()=='A'){
        //         st.pop();
        //     }
        //     else if(currchar=='D'&&st.top()=='C'){
        //         st.pop();
        //     }else{
        //         st.push(currchar);
        //     }


        // }
        // return st.size();
        int i=0;
        int j=1;
        while(j<n){
            if(i<0){
                i++;
                s[i]=s[j];
            }else if((s[i]=='A'&&s[j]=='B')||(s[i]=='C'&&s[j]=='D')){
                i--;
            }else{
                i++;
                s[i]=s[j];
            }
j++;
        }



return i+1;
    }
};