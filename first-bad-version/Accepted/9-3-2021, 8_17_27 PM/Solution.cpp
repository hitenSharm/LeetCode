// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,r=n;
        int ans;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(isBadVersion(m))
            {
                ans=m;
                r=m-1;
            }
            else
                l=m+1;
        }
        return ans;
    }
};