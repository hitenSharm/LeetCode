class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int>ump;
        sort(changed.begin(),changed.end());
        vector<int>ans;
        for(int i=changed.size()-1;i>=0;i--)
        {
            ump[changed[i]]++;
            if((ump[changed[i]*2]>0 and changed[i]!=0) || (changed[i]==0 and ump[changed[i]]-1>0))
            {
                ans.push_back(changed[i]);
                ump[changed[i]*2]--;
                ump[changed[i]]--;
            }            
        }        
        if(ans.size()*2==changed.size())
        return ans;
        
        return {};
    }
};