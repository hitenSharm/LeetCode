class Solution {
public:

    int comp(string t1,string t2)
    {
        for(int i=0;i<t1.size();i++)
        {
            if(t1[i]-'0'<t2[i]-'0')return 2;
            if(t1[i]-'0'>t2[i]-'0')return 1;
        }
        return 2;
    }

    string largestNumber(vector<int>& nums) {
        unordered_set<int>vis;
        string ans="";
        while(vis.size()!=nums.size())
        {
            int currIndex=-1;
            string maxi="-1";
            for(int i=0;i<nums.size();i++)
            {
                if(vis.find(i)!=vis.end())continue;
                if(currIndex==-1)
                {
                    maxi=to_string(nums[i]);
                    currIndex=i;
                    continue ;
                }
                string temp=to_string(nums[i]);
                int tAns=comp(temp+maxi,maxi+temp);
                if(tAns==1)
                {
                    maxi=temp;
                    currIndex=i;
                }
            }
            ans+=maxi;
            vis.insert(currIndex);
        }
        if(ans[0]=='0')ans="0";
        return ans;
    }
};