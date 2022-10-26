class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>ump;
        int s=0;
        int idx=0;
        //at any point for say k=5 we have 5m+a : a=1,2,3,4 so if we want subarray sum %5==0 we need to
        //cancel out the remainders(a) only way to do that is by getting a again b4r
        for(auto i:nums)
        {
            s+=i;            
            int y=s%k;
            if(((ump.find(y)!=ump.end() and idx-ump[y]>1) || (s%k==0 and idx>0)))return true;//i wish to cancel out the remainders!
            //1,0,1 type cases mein bhut quickly update ho jayega
            if(ump.find(y)==ump.end())
                ump[y]=idx;
            idx++;
        }
        return false;
    }
};