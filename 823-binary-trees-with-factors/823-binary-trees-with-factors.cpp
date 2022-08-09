class Solution {
public:
    long mod = 1e9 + 7;
    vector<long>dp;
    unordered_map<int, int>ump;
    long recu(int index, vector<int>& arr)
    {
        long ans = 1;//becomes root
        int curr = arr[index];
        if (dp[index] != -1)return dp[index];
        for (int i = 0; i < arr.size(); i++)
        {
            if (i == index || arr[i] > curr || curr % arr[i] != 0 || ump.find(curr/arr[i])==ump.end())continue;
            //if this index can serve as 2 children                        
            //make the child as new root and explore
            ans += (recu(i, arr) * recu(ump[curr / arr[i]], arr));
            ans %= mod;
        }
        return dp[index] = ans;
    }

    int numFactoredBinaryTrees(vector<int>& arr) {
        long ans = 0;
        dp.resize(arr.size(), -1);
        
        for(int i=0;i<arr.size();i++)ump[arr[i]]=i;

        for (int i = 0; i < arr.size(); i++)
        {
            ans += recu(i, arr);
            ans %= mod;
        }
        return ans;
    }
};