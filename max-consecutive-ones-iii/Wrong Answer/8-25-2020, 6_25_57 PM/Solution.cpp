// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int window=0;
        int winSoFar=0;
        for(int i=0;i<A.size();i++)
        {
         if(A[i]==1)
                window++;            
            if(A[i]==0){
                
                winSoFar=max(winSoFar,window+K);
                window=0;
            }
                   
        }
        return winSoFar;
    }
};