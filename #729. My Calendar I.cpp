class MyCalendar {
public:
vector<pair<int,int>> mp;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for(auto ele:mp){
            if(start<ele.second&&end>ele.first)
            return false;
        }
        mp.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */