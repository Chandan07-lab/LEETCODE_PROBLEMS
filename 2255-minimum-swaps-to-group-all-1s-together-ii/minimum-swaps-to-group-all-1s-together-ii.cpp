class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>t(2*n);
        for(int i=0;i<2*n;i++){
            t[i]=nums[i%n];
        }
        int cone=accumulate(begin(nums),end(nums),0);
        int i=0;
        int j=0;
        int curcount=0;
        int maxcount=0;
        while(j<2*n){
            if(t[j]==1){
                curcount++;
            }
            if(j-i+1>cone){
                curcount-=t[i];
                i++;
            }
            maxcount=max(maxcount,curcount);
            j++;
        }
        return cone-maxcount;
        
    }
};

// int cone=accumulate(begin(nums),end(nums),0);
// int i=0;
// int j=0;
// int currcount=0;
// int maxcount=0;
// while(j<2*n){
//     if(nums[j%n]==1){
//         currcount++;
//     }
//     if(j-i+1>currcount){
//         currcount-=nums[i%n];
//         i++;
//     }
//     maxcount=max(maxcount,currcount);
//     j++;
// }
// return countones-maxcount;
