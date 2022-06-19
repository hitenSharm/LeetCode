#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=0,r=n;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(guess(m)==1)
            {
                l=m+1;
            }
            else if(guess(m)==-1)
            {
                r=m;
            }
            else
            return m;
        }
        return -1;
    }
};