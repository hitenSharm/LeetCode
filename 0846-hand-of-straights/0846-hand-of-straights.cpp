#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        map<int,int>ump;
        
        for(auto i:hand)
            ump[i]++;                        
        
        for(auto i:ump)
        {
            if(i.second==0)continue ;
            //start element of that grp found, all elements usse bade aage aaynge agar exist
            //karte hai
            int len=0;
            int curr=i.first;
            int need=i.second;
            while(len<gs and ump.find(curr)!=ump.end() and ump[curr]>=need)
            {
                len++;                
                //need says ki 1 se start hone vale mein grps are controlled by number of 1's 
                //sab consecutives ka cnt need se >= hona chayiyhe
                ump[curr]-=need;//remove the taken elements                
                curr++;
            }
            if(len!=gs)return false;
        }
        return true;        
    }
};