class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs[0].size()==0)return "";
        int index=0;        
        while(true)
        {
            if(index>=strs[0].size())return strs[0];
            char compare=strs[0][index];
            for(int i=1;i<strs.size();i++)
            {
                if(strs[i][index]!=compare)
                {
                    return (index==0? "" : strs[i].substr(0,index));
                }
            }
            index++;
        }
    }
};