class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int maxind=-1;
        int count=0;
        for(int i=0;i<n;i++){
            maxind=max(maxind,arr[i]);
            if(maxind==i){
                count++;
            }
        }
        return count;
    }
};