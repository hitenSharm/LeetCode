class Solution {
public:
    void recu(int i,vector<int>& ans,string& s,int& k,int n)
    {
        if(n==0)
        {
            ans.push_back(stoi(s));
            return ;
        }
        if(i-k>=0)
        {
            int j=i-k;
            s=s+to_string(j);
            recu(j,ans,s,k,n-1);
            s.pop_back();
        }
        if(i+k<=9 and k!=0)
        {
            int j=i+k;
            s=s+to_string(j);
            recu(j,ans,s,k,n-1);
            s.pop_back();
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int i=1;i<=9;i++)
        {
            string s=to_string(i);
            recu(i,ans,s,k,n-1);
        }
        return ans;
    }
};