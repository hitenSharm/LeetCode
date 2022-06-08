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
    char findKthBit(int n, int k) {
        if(n==1)return '0';
		
		int len=pow(2,n)-1;
		if(k == (len+1)/2)return '1';
		
		if(k<=ceil(len/2))
		{			
			return findKthBit(n-1,k);
		}
		else
		{			
			if(findKthBit(n-1,len-k+1)=='0')return '1';
			else
			return '0';
		}
		return '0';
    }
};