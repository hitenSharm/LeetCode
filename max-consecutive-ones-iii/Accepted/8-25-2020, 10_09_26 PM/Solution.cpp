// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
         int i=0;
        int j=0;
        int max_len=0;
        while(i<A.size())
        {
            while(j<A.size())
            {
                if(A[j]==1)
                {
                    j++;
                }
                else if(K!=0)
                {
                    j++;
                    K--;
                }
                else
                {
                    break;
                }
            }
            max_len = max(max_len,j-i);
            if(j==A.size())
            {
                break;
            }
            while(i<A.size() && K==0)
            {
                if(A[i]==1)
                {
                    i++;
                }
                else
                {
                    i++;
                    K++;
                }
            }
        }
        return max_len;
    }
};