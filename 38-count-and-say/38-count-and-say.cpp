class Solution {
public:
    string countAndSay(int n) {
        string ans="1";        
        while(--n)
        {       
            string temp="";
            for(int i=0;i<ans.size();)
            {
                int j=i;
                while(j<ans.size() and ans[i]==ans[j])       
                {
                    j++;
                }
                int count = j-i;                
                temp+=to_string(count)+ans[i];
                i=j;
            }
            ans=temp;
        }
        return ans;
    }
};