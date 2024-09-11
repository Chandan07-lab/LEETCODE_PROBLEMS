class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count =0;
        //1st
        // while(start>0 || goal>0){
        //     if((start&1)!=(goal&1)){
        //         count++;
        //     }
        //     start=(start>>1);
        //     goal=(goal>>1);
        // }
        //2nd
        // int Xor = start^goal;
        // while(Xor){
        //     count+=(Xor&1);
        //     Xor=(Xor>>1);
        // }
        // return count;
    //3rd
    int Xor=start^goal;
    return __builtin_popcount(Xor);

    }
};