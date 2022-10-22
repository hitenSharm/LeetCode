class Solution {
public:
    
    bool notValid(unordered_map<char,int>& req,unordered_map<char,int>& compare)
    {
        for(auto i:req)
        {
            if(i.second>compare[i.first])return true;
        }
        return false;
    }
    
    string getString(int i,int j,string& s)
    {
        string ans="";
        while(i<=j)
        {
            ans+=s[i];
            i++;
        }
        //cout<<ans<<endl;
        return ans;
    }
    
    string minWindow(string s, string t) {
        unordered_map<char,int>req;
        unordered_map<char,int>compare;
        
        if(s.size()<t.size())return "";
        
        for(auto i:t)
        {
            req[i]++;
        }
        
        int i=0,j=0;
        int ans=INT_MAX;
        int ni,nj;
        while(i<s.size())
        {
            while(j<s.size() and notValid(req,compare))
            {
                //cout<<s[j]<<" ";
                compare[s[j]]++;
                j++;
            }
            //cout<<endl;
            if(!notValid(req,compare)){
                if(ans>j-i){
                    ans=j-i;
                    ni=i;
                    nj=j-1;
                }
            }
            compare[s[i]]--;
            i++;
        }
        if(ans!=INT_MAX)
        {
         //   cout<<"here";
            string res=getString(ni,nj,s);
            return res;
        }        
        return "";
    }
};