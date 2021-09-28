class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n=arr.size();
        if(n==m)return n;
        
        set<pair<int,int>>p;
        p.insert({1,n});
        int step=0;
        for(int i=n-1;i>=0;i--)
        {
            if(p.empty())break;   
            
            auto it=p.upper_bound({arr[i],INT_MAX});
            it--;
            int l=it->first,r=it->second;
            p.erase(it);
            int prevFilledOnes1=arr[i]-l,prevFilledOnes2=r-arr[i];
            if(prevFilledOnes1==m || prevFilledOnes2==m)return n-step-1;
            if(prevFilledOnes1>=1)p.insert({l,arr[i]-1});
            if(prevFilledOnes2>=1)p.insert({arr[i]+1,r});
            step++;
        }
        return -1;
    }
};