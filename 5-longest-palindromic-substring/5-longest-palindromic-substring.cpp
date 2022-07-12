class Solution {
public:
    string substring(int i,int j,string& s)
    {
        string ans="";
        for(int k=i;k<=j;k++)ans+=s[k];
        return ans;
    }
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(i+1<s.size() and s[i]==s[i+1])
            {
                int j=i+1;
                int ti=i;
                while(ti>=0 and j<s.size() and s[ti]==s[j])
                {
                    ti--;
                    j++;
                }
                string temp=substring(ti+1,j-1,s);
                if(ans.size()<temp.size())ans=temp;
            }
            int ti=i-1,j=i+1;
            while(ti>=0 and j<s.size() and s[ti]==s[j])
            {
                ti--;
                j++;
            }
                //cout<<ti+1<<" "<<j-1<<" ";
            string temp=substring(ti+1,j-1,s);
            if(ans.size()<temp.size())ans=temp;
        }
        return ans;
    }
};