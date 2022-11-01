class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans="";
        for(int i=0;i<s.size();)
        {
            if(s[i]==' '){
                i++;
                continue ;
            }
            string temp="";
            while(i<s.size() and s[i]!=' ')
            {
                temp+=s[i];
                i++;
            }
            int j=0;
            int ii=temp.size()-1;
            while(j<=ii)
            {
                swap(temp[ii],temp[j]);
                j++;
                ii--;
            }
            ans+=temp;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};