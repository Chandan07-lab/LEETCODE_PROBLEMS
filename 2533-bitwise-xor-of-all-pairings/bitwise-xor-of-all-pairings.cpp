class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

       int Xor=0;

       if(m%2!=0){
        for(int &nums:nums2){
        Xor^=nums;
        }
       } 

       if(n%2!=0){
        for(int &nums:nums1){
            Xor^=nums;
        }
       }
        
        return Xor;
    }
};