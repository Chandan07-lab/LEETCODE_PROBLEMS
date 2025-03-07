class Solution {
public:
vector<bool>iseive(int right){
    vector<bool>isprime(right+1,true);
    isprime[0]=false;
    isprime[1]=false;
    for(int i=2;i*i<=right;i++){
        if(isprime[i]){
            for(int j=i*i;j<=right;j+=i){
                isprime[j]=false;
            }
        }
    }

    return isprime;
}
    vector<int> closestPrimes(int left, int right) {
        vector<bool>isprime=iseive(right);

        vector<int>prime;
        for(int i=left;i<=right;i++){
            if(isprime[i]){
                prime.push_back(i);
            }
        }

        int minn=INT_MAX;

        vector<int>result={-1,-1};

        for(int i=1;i<prime.size();i++){
            int diff=prime[i]-prime[i-1];

            if(diff<minn){
                minn=diff;
                result={prime[i-1],prime[i]};
            }

        }

     return result;
    }
};