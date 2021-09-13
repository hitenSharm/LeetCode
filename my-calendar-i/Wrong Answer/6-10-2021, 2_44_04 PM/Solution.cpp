// https://leetcode.com/problems/my-calendar-i

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class MyCalendar {
public:
    MyCalendar() {
       
    }
    vector<vector<int>>booked; 
    bool book(int start, int end) {
        vector<int>temp;temp.push_back(start);temp.push_back(end);
        booked.push_back(temp);
        if(booked.size()==0)
        {          
          return true;
        }
        sort(booked.begin(),booked.end());
        int minEnd=booked[0][1];int j=1;
        while(j<booked.size())
        {
          if(minEnd>booked[j][0])
          {
            booked[j].clear();
            return false;
          }
          minEnd=booked[j][1];
          j++;          
        }        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */