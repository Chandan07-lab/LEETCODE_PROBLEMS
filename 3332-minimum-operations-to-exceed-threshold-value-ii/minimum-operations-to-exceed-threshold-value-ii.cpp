class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long,vector<long>,greater<long>>pq(nums.begin(),nums.end());
       
        int count=0;
        while(!pq.empty() && pq.top()<k ){
            long hi=pq.top();
            pq.pop();
            long sechi=pq.top();
            pq.pop();

         pq.push(hi*2+sechi);
            count++;
        }
        return count;
    }
};