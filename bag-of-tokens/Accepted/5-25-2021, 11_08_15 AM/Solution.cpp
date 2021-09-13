// https://leetcode.com/problems/bag-of-tokens

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
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i=0;
        int j=tokens.size()-1;
        int score=0;
        sort(tokens.begin(),tokens.end());
        int ts=0;
        while(i<=j && i<tokens.size() && j>=0)
        {            
        	while(i<=j && i<tokens.size() && tokens[i]<=power)
        	{
        		power=power-tokens[i];
        		i++;                
        		ts++;
        		score=max(score,ts);
        	}            
        	while(j>=i && j>=0 && i<tokens.size() && power<tokens[i] && ts>0)
        	{
        		power=power+tokens[j];
        		j--;                
        		ts--;
        		score=max(score,ts);
        	}             
            if(i==j || (i<tokens.size() and tokens[i]>power))
                break;
        }
        return score;
    }
};