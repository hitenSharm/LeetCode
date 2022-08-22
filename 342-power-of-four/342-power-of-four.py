class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if(n==0):
            return False
        return n>0 and log2(n) % 2==0
        