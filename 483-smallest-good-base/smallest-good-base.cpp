class Solution {
public:
    string smallestGoodBase(string n) {
        long long num=stoll(n);
        for(int i=64;i>2;i--){
            long long l=2;
            long long h=num-1;
            while(l<=h){
                long long mid=l+(h-l)/2;
                long long val=1;
                long long cur=1;
                for(int j=1;j<i;j++){
                    if(cur>(num-val)/mid){
                        val=num+1;
                        break;
                    }

                    cur*=mid;
                    val+=cur;
                }
                if(val==num){
                    return to_string(mid);
                }else if(val>num){
                    h=mid-1;
                }else{
                    l=mid+1;
                }
            }
        }
        return to_string(num-1);
    }
};