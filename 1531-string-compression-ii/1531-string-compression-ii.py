class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        @lru_cache(None)
        
        def dp(idx,lastChar,lastCnt,k):
            if k<0:
                return float('inf')
            if idx==n:
                return 0
            
            #delete char
            dlt=dp(idx+1,lastChar,lastCnt,k-1)
            
            #keep char
            if s[idx]==lastChar:
                keep=dp(idx+1,lastChar,lastCnt+1,k) + (lastCnt in [1,9,99])
            else:
                keep=dp(idx+1,s[idx],1,k) + 1 #as its not equal so it means we start from here
            return min(dlt,keep)
        
        n=len(s)
        return dp(0,"",0,k)
        