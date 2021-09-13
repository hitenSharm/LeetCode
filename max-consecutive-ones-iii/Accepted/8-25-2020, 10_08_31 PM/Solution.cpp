// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int window=0;
        int k=K;
        int winSoFar=0;
        int n=A.size();
        for(int i=0,j=0;i<A.size();i++)
        {
            while(j<n){
                if(A[j]==1)
                {
                    window++;
                }
                else if(K!=0)
                {
                    window++;
                    K--;
                }
                else
                {
                    break;
                }
                j++;
            }
            winSoFar=max(winSoFar,window);
            window--;
            if(A[i]==0)
                K++;
        }
        return winSoFar;
    }
};