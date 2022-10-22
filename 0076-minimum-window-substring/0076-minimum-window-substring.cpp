class Solution {
public:        
    
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
        
        if(s.size()<t.size())return "";
        
        for(auto i:t)
        {
            req[i]++;
        }
        
        int i=0,j=0;
        int cnt=t.size();
        int ans=INT_MAX;
        int ni,nj;
        while(i<s.size())
        {
            while(cnt>0 and j<s.size()){
                if(req[s[j]]>0)cnt--; //means its in actual t string(>0 condition)
                req[s[j]]--;//
              //  cout<<s[j]<<" ";
                j++;
            }
            //cout<<endl;            
            //remove unnecessary
            //cout<<"removal \n";
            while(i<s.size() and req[s[i]]<0 and i<j)//less than 0 means unnecessary
            {
              //  cout<<s[i]<<" ";
                req[s[i]]++;                
                i++;
            }
            //cout<<endl;
            if(ans>j-i and cnt==0){
                    ans=j-i;
                    ni=i;
                    nj=j-1;
            }
            cnt++;//now i am at neccesary char
            req[s[i]]++;
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