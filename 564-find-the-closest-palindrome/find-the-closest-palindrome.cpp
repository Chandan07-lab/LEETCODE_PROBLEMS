class Solution {
public:
long htp(long l,bool ev){
    long re=l;
    if(!ev){
        l=l/10;
    }
    while(l>0){
        int di=l%10;
        re=(re*10)+di;
        l/=10;
    }
    return re;
}


    string nearestPalindromic(string n) {
        int len=n.size();
        int mid=len/2;
        long fh=stol(n.substr(0,len%2==0? mid:mid+1));
vector<long> pr;
pr.push_back(htp(fh,len%2==0));
pr.push_back(htp(fh+1,len%2==0));
pr.push_back(htp(fh-1,len%2==0));
pr.push_back((long)pow(10,len-1)-1);
pr.push_back((long)pow(10,len)+1); 

long diff= LONG_MAX;
long re=0;
long orig=stol(n); 

for(long &nu: pr){
    if(nu==orig) continue;
    if(abs(nu-orig)<diff){
        diff=abs(nu-orig);
        re=nu;
    }else if(abs(nu-orig)==diff){
        re=min(re,nu);
    }
}
return to_string(re);
    }
};