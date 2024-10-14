class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());//insertion(o(n)) time complexity;
        long long sum =0;
        while(k--){
            int maxel=pq.top();
            pq.pop();
            sum+=maxel;
            int el=ceil(maxel/3.0);//its takes (o(logn));
            pq.push(el);
        }
        return sum;
    }
};