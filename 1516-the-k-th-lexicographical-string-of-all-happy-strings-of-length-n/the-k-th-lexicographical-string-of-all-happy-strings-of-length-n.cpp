class Solution {
public:
void solve(string& curr,string& result,int &count,int n,int k){
    if(curr.length()==n){
        count++;
        if(count==k){
            result=curr;
        }
        return;
    }

    for(char ch='a';ch<='c';ch++){
        if(!curr.empty() && curr.back()==ch){
            continue;
        }

        curr.push_back(ch);

        solve(curr,result,count,n,k);
        curr.pop_back();
    }
}


    string getHappyString(int n, int k) {
        string curr="";
        string result="";
        int count=0;
        solve(curr,result,count,n,k);
        
        return result;
        
    }
};