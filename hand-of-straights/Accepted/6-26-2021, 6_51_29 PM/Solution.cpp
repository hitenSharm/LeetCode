// https://leetcode.com/problems/hand-of-straights

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
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int>s;
        
        for(int i=0;i<hand.size();i++)
        s.insert(hand[i]);
        
        int subs=0;
        sort(hand.begin(),hand.end());
        
        for(int i=0;i<hand.size();i++)
        {
            if(s.find(hand[i])==s.end())continue;
            int len=0;
            int numToFind=hand[i];
            while(len<groupSize)
            {
                if(s.find(numToFind)!=s.end())
                {
                    auto it = s.find(numToFind);
                    numToFind++;
                    len++;
                    s.erase(it);
                }
                else
                return false;
            }            
        }       
        return true;
    }
};