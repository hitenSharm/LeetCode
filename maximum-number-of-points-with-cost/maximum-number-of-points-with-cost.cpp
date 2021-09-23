class Solution {
public:    
    long long maxPoints(vector<vector<int>>& points) {
        long long m=points.size(),n=points[0].size();
        vector<long long>prev(n);
        for(long long i=0;i<n;i++)prev[i]=points[0][i];
        for(long long i=0;i<m-1;i++)
        {
            vector<long long>left(n,0),ryt(n,0);
            left[0]=prev[0];
            ryt[n-1]=prev[n-1];
            
            for(long long j=1;j<n;j++)
            {
                left[j]=max(left[j-1]-1,prev[j]);
            }
            for(long long j=n-2;j>=0;j--)
            {
                ryt[j]=max(ryt[j+1]-1,prev[j]);
            }
            
            for(long long j=0;j<n;j++)
            prev[j]=points[i+1][j]+max(left[j],ryt[j]);
        }
        long long ans=0;
        for(long long i=0;i<n;i++)
        {
            if(ans<prev[i])ans=prev[i];
        }
        return ans;
    }
};