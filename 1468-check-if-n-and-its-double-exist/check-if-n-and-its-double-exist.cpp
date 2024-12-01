class Solution {
public:
int bsearch(vector<int>&arr,int tar){
    int l=0;
    int r=arr.size()-1;
    int mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(arr[mid]==tar){
            return mid;
        }else if(arr[mid]>tar){
            r=mid-1;
        }else{
            l=mid+1;
        }   
     }

     return -1;
}
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int j=bsearch(arr,2*arr[i]);
            if(j!=-1 && j!=i){
                return true;
            }
        }
        return false;
    }
};