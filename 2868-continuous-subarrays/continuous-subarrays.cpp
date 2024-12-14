class Solution {
public:
#define P pair<int,int>
    long long continuousSubarrays(vector<int>& nums) {
    int n= nums.size();
    priority_queue<P,vector<P>,greater<P>>minheap;
    priority_queue<P> maxheap;

    int i=0;
    int j=0;
    long long count=0;

    while(j<n){
        minheap.push({nums[j],j});
        maxheap.push({nums[j],j});

        while((maxheap.top().first - minheap.top().first)> 2){
            i++;
         while(!maxheap.empty() && maxheap.top().second< i){
            maxheap.pop();
         }   
        while(!minheap.empty() && minheap.top().second < i){
            minheap.pop();
        }

        }
        count+=j-i+1;
        j++;

    }
    return count;
    }
};