class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int & a,int & b){
            string s1=to_string(a);
            string s2=to_string(b);
             return (s1+s2)>(s2+s1);

        });
        if(nums[0]==0){
            return "0";
        }
        string re="";
        for(int &num:nums){
            string ad=to_string(num);
            re+=ad;
        }
        return re;
    }
};