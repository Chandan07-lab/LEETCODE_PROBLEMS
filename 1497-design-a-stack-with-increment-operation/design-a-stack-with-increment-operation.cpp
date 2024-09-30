class CustomStack {
public:
vector<int>st;
vector<int>incre;
int n;
    CustomStack(int maxSize) {
      n=maxSize;  
    }
    
    void push(int x) {
        if(st.size()<n){
            st.push_back(x);
            incre.push_back(0);
        }
        
    }
    
    int pop() {
        if(st.size()==0){
            return -1;
        }
        int idx=st.size()-1;
        if(idx>0){
            incre[idx-1]+=incre[idx];
        }
        int tval=st[idx]+incre[idx];
        st.pop_back();
        incre.pop_back();
        return tval;
        
    }
    
    void increment(int k, int val) {
        int idx=min(k,(int)st.size())-1;
        if(idx>=0){
            incre[idx]+=val;
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */