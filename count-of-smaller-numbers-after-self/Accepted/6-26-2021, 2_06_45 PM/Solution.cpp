// https://leetcode.com/problems/count-of-smaller-numbers-after-self

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:

    vector<int>bitPos;
    vector<int>bitNeg;
    
    void update(int index,int val,int fl)
    {
        if(index==0)index++;
        int n=bitNeg.size();
        if(fl==1)n=bitPos.size();
        for(;index<n;index+=(index & -index))
        {
            if(fl==1)
            bitPos[index]+=val;
            else
            bitNeg[index]+=val;
        }
    }
    
    int sum(int index,int fl)
    {
        if(index==0) return 0;
        int ans=0;
        for(;index>0;index-=(index & -index))
        {
            if(fl==1)
            ans+=bitPos[index];
            else
            ans+=bitNeg[index];
        }
        return ans;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        unordered_map<int,int>ump;
        vector<int>cnt;
        bitPos.resize(abs(maxi)+1,0);
        bitNeg.resize(abs(mini)+1,0);
        int nega=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]>0)
            {
                update(nums[i],1,1);
                int tmp=sum(maxi,1)-sum(nums[i],1);
                tmp=nums.size()-i-1-tmp-ump[nums[i]];
                cnt.push_back(tmp);
            }
            if(nums[i]<0)
            {
                nega++;
                update(abs(nums[i]),1,0);
                int tmp=sum(abs(mini),0)-sum(abs(nums[i]),0);
                cnt.push_back(tmp);
            }
            if(nums[i]==0)
            cnt.push_back(nega);
            
            ump[nums[i]]++;
        }
        reverse(cnt.begin(), cnt.end());
        return cnt;
        
    }
};