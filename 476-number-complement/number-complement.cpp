class Solution {
public:
    int findComplement(int num) {
        int no=(int)(log2(num))+1;

        for(int i=0;i<no;i++){
            num=num^(1<<i);
        }
        return num;
    }
};

// if(num=0)
// return 1;

// int no=(int)(log2(num))+1;
// unsigned int mask=(1U<<no)-1;

// return num^mask;

// int i=0;ans=0;
// while(num){
//     if(!(num & 1)){
//     ans|=(1<<i);
//     }
//     num>>=1;;
//     i++;
// }
// return ans;