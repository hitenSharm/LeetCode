class Solution {
    private:
    vector<string>ans;
    public:
    
    bool isvalid(string& res)
    {        
        int dots=0;
        string tempNum="";
        for(int i=0;i<res.size();i++)
        {            
            if(res[i]=='.'){
                dots++;
                if(tempNum.size()>1 and tempNum[0]=='0')return false;
                int x=stoi(tempNum);
                if(x>255)return false;
                tempNum="";
            }
            else if(!isdigit(res[i]))return false;
            else
                tempNum+=res[i];
        }
        if(tempNum.size()>1 and tempNum[0]=='0')return false;
        int x=stoi(tempNum);
        if(x>255)return false;
        return dots==3;
    }
    
    void recu(string& s,string temp,int index)
    {
        if(index>=s.size())
        {
            if(isvalid(temp))
            {
                ans.push_back(temp);                
            }
            return ;
        }
        for(int i=index;i<=index+2 and i<s.size();i++)
        {
            if(i==s.size()-1)temp+=s[i];
            else
                temp=temp + s[i]+".";
            recu(s,temp,i+1);
            if(temp.back()=='.')temp.pop_back();
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        string temp="";
        recu(s,temp,0);
        return ans;
    }
};