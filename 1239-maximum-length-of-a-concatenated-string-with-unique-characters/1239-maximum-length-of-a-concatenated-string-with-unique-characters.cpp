class Solution {
public:
    
    bool valid(unordered_set<char>& ust,string& s)
    {
        for(auto i:s)
        {
            if(ust.find(i)!=ust.end())return false;
        }
        return true;
    }
    
    int max(int a,int b)
    {
        return (a>=b ? a : b);
    }
    
    int recu(unordered_set<char>& ust,vector<string>& arr,int idx)
    {
        if(idx>=arr.size())return 0;
        int ans=0;
        
        if(valid(ust,arr[idx]))
        {
            for(auto i:arr[idx]){
                ust.insert(i);
            }
            ans=max(ans,arr[idx].size()+recu(ust,arr,idx+1));
            for(auto i:arr[idx]){
                ust.erase(i); //unmake move
            }
        }
        ans=max(ans,recu(ust,arr,idx+1));
        return ans;
    }
    
    int maxLength(vector<string>& arr) {
        
        unordered_set<char>ust;
        vector<string> clean;
        for(auto i:arr)
        {
            int freq[26]={0};
            bool fl=true;
            for(auto j:i)
            {
                if(freq[j-'a']>=1){
                    fl=false;
                    break ;
                }
                freq[j-'a']++;
            }
            if(fl)clean.push_back(i);
        }
        
        return recu(ust,clean,0);        
    }
};