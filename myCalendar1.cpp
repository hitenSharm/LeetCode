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
    map<int,int> booked;
    bool book(int start, int end) {
       if(booked.size()==0)
       {
          booked.insert({start,end});
          return true;
       }
       auto it=booked.upper_bound(start);
       if(it!=booked.begin())
       {
        auto it2=prev(it,1);
        if(start<it2->second) return false;
       }
       if(it!=booked.end())
       {
        if(it->first<end)return false;
       }
       booked.insert({start,end});
       return true;
      
    }
};