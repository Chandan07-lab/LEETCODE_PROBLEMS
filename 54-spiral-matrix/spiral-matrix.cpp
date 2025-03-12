class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==0){
            return {};
        }

        vector<int>r;
        int top=0;
        int right=n-1;
        int down=m-1;
        int left=0;
        int id=0;

        while(top<=down && left<=right){

            if(id==0){
                for(int i=left;i<=right;i++){
                    r.push_back(matrix[top][i]);
                }
                top++;
            }
            if(id==1){
                for(int i=top;i<=down;i++){
                    r.push_back(matrix[i][right]);
                }
                right--;
            }
            if(id==2){
                for(int i=right;i>=left;i--){
                    r.push_back(matrix[down][i]);
                }
                down--;
            }

            if(id==3){
                for(int i=down;i>=top;i--){
                    r.push_back(matrix[i][left]);
                }
                left++;
            }

            id=(id+1)%4;
        }

        return r;
    }
};