// https://leetcode.com/problems/reorganize-string

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
    string reorganizeString(string s) {
        int hashArr[26]={0};
        string ans;int maxi=0;char maxEle;
        for(char i:s)
        {
          ans=ans+"#";
          hashArr[i-'a']++;            
          if(maxi<hashArr[i-'a'])
          {
            maxi=hashArr[i-'a'];
            maxEle=i;
          }
        }

        if(maxi>((s.length()+1)/2)){
          return "";
        }

        int ev=0;int od=1;
        
        while(ev<s.length() && hashArr[maxEle-'a']>0)
        {
          ans[ev]=maxEle;
          hashArr[maxEle-'a']--;
          ev=ev+2;
        }        
        for(int i=0;i<26;i++)
        {            
          if(hashArr[i]==0)continue;
          char temp=(char)(i+'a');            
          while(hashArr[i]>0)
          {
              if(ev<s.length())
              {
                ans[ev]=temp;
                ev=ev+2;
                hashArr[i]--;
                continue;
              }
            if(od<s.length())
            {
              ans[od]=temp;
              od=od+2;
              hashArr[i]--;
              continue;
          }
          }
        }
    return ans;
    }
};