class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int>fwdMap;
        unordered_map<int,int>bwdMap;
        int s1=0,s2=0;
        int len=INT_MAX;
        int arrSize=nums.size();
        for(int i=0,j=nums.size()-1;i<nums.size() and j>=0;++i,--j)
        {
            s1+=nums[i];
            s2+=nums[j];
            fwdMap[s1]=i;
            bwdMap[s2]=j;
            if(s1==x)len=min(len,i+1);
            if(s2==x)len=min(len,arrSize-j);
        }
        for(auto it:fwdMap)
        {            
            if(bwdMap.find(x-it.first)!=bwdMap.end() and bwdMap[x-it.first]>it.second)
            {
                int tlen=it.second+1+nums.size()-bwdMap[x-it.first];
                len=min(len,tlen);
            }
        }
        if(len==INT_MAX)len=-1;
        return len;
    }
};