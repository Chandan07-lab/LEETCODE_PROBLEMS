class Solution {
public:
int find_firstp(vector<int>&nums,int t){
    int l=0;
    int r=nums.size()-1;
    int result=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]==t){
            result=mid;
            r=mid-1;
        }else if(nums[mid]>t){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return result;
}
int find_lastp(vector<int>&nums,int t){
    int l=0;
    int r=nums.size()-1;
    int result=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]==t){
            result=mid;
            l=mid+1;
        }else if(nums[mid]>t){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return result;

}
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=find_firstp(nums,target);
        int r=find_lastp(nums,target);

        return {l,r};
    }
};