class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dir= {{0,1}, //east
                                {1,0},//south
                                {0,-1},//west
                                {-1,0}//north
        };
        vector<vector<int>> re;
        int step=0;
        int d=0;
        re.push_back({rStart,cStart});
        while(re.size()<rows*cols){
            if(d==0 || d==2) step++;

            for(int i=0; i<step;i++){
                rStart+=dir[d][0];
                cStart+=dir[d][1];

                if(rStart>=0 && rStart<rows && rows && cStart>=0 && cStart<cols)
                re.push_back({rStart,cStart});
            }
            d=(d+1)%4;

}       
return re;
        
    }
};