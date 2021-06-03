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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size()==1 && n==1 && flowerbed[0]==0)
            return true;
        for(int i=0;i<flowerbed.size();i++)
        {
          if(n==0)return true;
          if(i==0 && i+1<flowerbed.size() && flowerbed[i]==0 && flowerbed[i+1]==0)
          {
            n--;
            flowerbed[i]=1;
            continue;
          }
          if(i<flowerbed.size()-1 && i>0 && flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0)
          {
            n--;
            flowerbed[i]=1;
            continue;
          }
          if(i==flowerbed.size()-1 && i>0 && flowerbed[i]==0 && flowerbed[i-1]==0)
          {
            n--;
            flowerbed[i]=1;
            continue; 
          }
        }
        if(n==0)return true;

        return false;
    }
};