class Solution {
public:
unordered_map<int,string>mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
 void solve(int index,string digits,vector<string>&ans,string &temp){
    if(index==digits.size()){
        ans.push_back(temp);

        return;
    }
    int num=digits[index]-'0';
    string letter=mp[num];
    for(int i=0;i<letter.size();i++){
        temp.push_back(letter[i]);
        solve(index+1,digits,ans,temp);

        temp.pop_back();
    }
 }
 
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0){
            return ans;
        }
        string temp="";
        solve(0,digits,ans,temp);
      
      return ans;

    }
};