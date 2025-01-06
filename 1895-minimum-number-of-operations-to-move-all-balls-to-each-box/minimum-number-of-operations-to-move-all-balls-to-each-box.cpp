class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>answer(n,0);

        int cumvalue=0;
        int cumvaluesum=0;

        for(int i=0;i<n;i++){
            answer[i]=cumvaluesum;
            cumvalue+=boxes[i]=='0'?0:1;
            cumvaluesum+=cumvalue;
        }
        cumvalue=0;
        cumvaluesum=0;
        for(int i=n-1;i>=0;i--){
            answer[i]+=cumvaluesum;
            cumvalue+=boxes[i]=='0'?0:1;
            cumvaluesum+=cumvalue;
        }
        return answer;
    }
};