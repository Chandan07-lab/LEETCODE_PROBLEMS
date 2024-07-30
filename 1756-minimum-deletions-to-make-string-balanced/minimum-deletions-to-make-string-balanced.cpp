class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();

        int ca=0;;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a')
            ca++;
        }
        int count=INT_MAX;
        int cb=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a')
            ca--;
            count=min(count,cb+ca);
            if(s[i]=='b')
            cb++;
        }
        return count;
        
    }
};
// int minimumDeletions(string s) {
//         int n=s.length();
//         int count = 0;
//         stack<char> s;
// for(int i=0;i<n;i++){
//     if(!s.empty()&&s[i]=='a'&&s.top()++'b'){
//         s.pop();
//         count++;
//     }else{
//         s.push(s[i]);
//     }
// }
// return count;
// }
// };