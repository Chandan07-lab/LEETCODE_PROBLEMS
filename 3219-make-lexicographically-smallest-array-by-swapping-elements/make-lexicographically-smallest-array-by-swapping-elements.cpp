class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n= nums.size();

        vector<int>vec=nums;

        sort(vec.begin(),vec.end());
        int group=0;

        unordered_map<int,int>numtogroup;
        numtogroup[vec[0]]=group;

        unordered_map<int,list<int>>grouptolist;
        grouptolist[group].push_back(vec[0]);

        for(int i=1;i<n;i++){
            if(abs(vec[i]-vec[i-1])>limit){
                group+=1;
            }

            numtogroup[vec[i]]=group;
            grouptolist[group].push_back(vec[i]);
        }

        vector<int>result(n);
        for(int i=0;i<n;i++){
            int num=nums[i];
            int groups=numtogroup[num];
            result[i]=*grouptolist[groups].begin();
            grouptolist[groups].pop_front();
        }

    return result;
        
    }
};