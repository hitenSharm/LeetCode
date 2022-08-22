class Solution {
public:
    
    string justify(string temp,int& width,bool isEnd)
    {
        if(temp.size()==width)return temp;
        int spaces=0;
        for(auto i:temp)
        {
            if(i==' ')spaces++;
        }
        int toInsert=width-temp.size();
        if(isEnd || spaces==0)
        {
            temp.insert(temp.size(),toInsert,' ');//ex if justification is the second last in the string vector
            return temp;
        }
        int eachSlot=toInsert/spaces;
        int extras=toInsert%spaces;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]==' '){
                int addMore=eachSlot+(extras-- >0 ? 1 : 0);
                temp.insert(i,addMore,' ');
                i+=addMore;
            }
        }
        return temp;
    }
    
    vector<string> fullJustify(vector<string>& word, int maxWidth) {
        //put in string => justify spaces
        vector<string>ans;
        string temp=word[0];
        for(int i=1;i<word.size();i++)
        {
            if(temp.size()+word[i].size() + 1<=maxWidth)
            {
                temp+=" "+word[i];
            }
            else
            {
                //justify spaces
                bool isEnd = false;
                string justified=justify(temp,maxWidth,isEnd);
                ans.push_back(justified);
                temp=word[i];
            }
        }
        ans.push_back(justify(temp,maxWidth,true));
        return ans;
    }
};