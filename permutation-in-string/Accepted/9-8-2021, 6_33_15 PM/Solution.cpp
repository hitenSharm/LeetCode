// https://leetcode.com/problems/permutation-in-string

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
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>ump;        
        for(char i:s1)
          ump[i]++;
        unordered_map<char,int>temp=ump; 
        int i=0;        
        int j=0;
        while(i<s2.length())
        {
            while(j<s2.length() && temp.find(s2[j])!=temp.end() && j>=i)
            {              
              temp[s2[j]]--;
              if(temp[s2[j]]==0)
              temp.erase(s2[j]);
              if(temp.size()==0)
                return true;
              j++;
            }
            
            if(ump.find(s2[i])!=ump.end())
            {              
              temp[s2[i]]++;              
            }
            
            i++;
            
            if(j<i)
                j=i;

        }
        return false;
    }
};