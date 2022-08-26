class Solution {
public:
    
    bool isAnagram(string& s1,string s2)
    {
        unordered_map<int,int>ump;
        for(auto i:s2)ump[i-'0']++;
        
        for(auto i:s1)
        {
            ump[i-'0']--;            
            if(ump[i-'0']<0)return false;
        }        
        for(auto i:ump)
            if(i.second>0)return false;
        return true;
    }
    
    bool reorderedPowerOf2(int n) {
        long r=1000000000;
        long l=1;
        string comp=to_string(n);
        while(l<=r)
        {
            if(isAnagram(comp,to_string(l)))return true;
            //cout<<l<<endl;
            l=l*2;
        }
        return false;
    }
};