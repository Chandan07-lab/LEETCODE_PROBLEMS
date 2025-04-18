class Solution {
public:
#define ll unsigned long long
int m= 1e9+7;

vector<int>getNSL(vector<int>&arr,int n){
    vector<int>result(n);
    stack<int>st;
    
    for(int i=0;i<n;i++){

        if(st.empty()){
            result[i]=-1;
        }else{
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }

            result[i]= st.empty()?-1:st.top();
        }
        st.push(i);
    }
    return result;
}

vector<int>getNSR(vector<int>&arr,int n){
    vector<int>result(n);
    stack<int>st;
    
    for(int i=n-1;i>=0;i--){

        if(st.empty()){
            result[i]=n;
        }else{
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }

            result[i]= st.empty()?n:st.top();
        }
        st.push(i);
    }
    return result;
}



    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nsl =getNSL(arr,n);
        vector<int>nsr =getNSR(arr,n);

        ll sum=0;
        for(int i=0;i<n;i++){
            ll d1=i-nsl[i];
            ll d2=nsr[i]-i;

            ll totalways=d1*d2;
            ll sum_oftotalway=arr[i]*totalways;

            sum=(sum+sum_oftotalway)%m;
        }
        return sum;
    }
};