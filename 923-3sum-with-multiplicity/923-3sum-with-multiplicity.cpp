class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<long long,long long>ump;
        for(auto i:arr)ump[i]++;
        long long ans=0;
        long long mod=1e9+7;
        for(auto it:ump)
        {
            for(auto it2:ump)
            {
                int i=it.first,j=it2.first,k=target-(i+j);
                if(!ump.count(k))continue;
                if(i==j and j==k)
                ans += ump[i] * (ump[i] - 1) * (ump[i] - 2) / 6; //nC3 if j count is not possibel then 0 automatically
                else if(i==j and j!=k)
                ans+=ump[i] * (ump[i] - 1) / 2 * ump[k]; //nC2 * ump[k];
                else if(i<j and j<k)
                ans+=ump[i]*ump[j]*ump[k];
            }
        }
        return ans%mod;
    }
};