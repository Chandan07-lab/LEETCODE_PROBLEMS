class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR=0;
        for(int &der:derived){
            XOR^=der;
        }

        return XOR==0;
    }
};