// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:
    
    int totalFruit(vector<int>& tree) {
        int i=0;
        int j=0;
        unordered_map<int,int>ump;
        int len=0;
        int nz=0;
        for(;i<tree.size();i++)
        {
            while(j<tree.size() && nz<=2)
            {                
                if(ump[tree[j]]==0)
                nz++;
                
                if(nz<=2)
                {
                    ump[tree[j]]++;
                    j++;
                }
            }           
            len=max(len,j-i);          
            ump[tree[i]]--;
            if(ump[tree[i]]==0)
            {
                nz--;
                if(j<tree.size())
                ump[tree[j]]++;               
            }
        }
        return len;
        
    }
};