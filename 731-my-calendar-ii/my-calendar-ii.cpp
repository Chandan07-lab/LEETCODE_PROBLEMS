class MyCalendarTwo {
public:
vector<pair<int,int>>doubleolapreg;
vector<pair<int,int>>overallreg;
bool checkoverlap(int s1,int e1,int s2,int e2){
    return max(s1,s2)<min(e1,e2);
}
pair<int,int>findoverlap(int s1, int e1,int s2,int e2){
    return {max(s1,s2),min(e1,e2)};
}
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(pair<int,int>reg:doubleolapreg){
            if(checkoverlap(reg.first,reg.second, start, end)){
                return false;
            }
        }
        for(pair<int,int>reg:overallreg){
            if(checkoverlap(reg.first,reg.second, start, end)){
                doubleolapreg.push_back(findoverlap(reg.first,reg.second, start, end));
            }
        }
        overallreg.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */