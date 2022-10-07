class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {
        
    }
    
    int book(int s, int e) {
        int now = 0;
        int ans = 0;
        
        mp[s]++;
        mp[e]--;
        
        for(auto i: mp)
        {
            now += i.second;
            ans = max(ans,now);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */