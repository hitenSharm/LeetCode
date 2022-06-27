class Solution {
public:

    vector<vector<int>>ans;
    int maxiK;
    void recu(int k,int curr,int s,int &n,vector<int>& temp)
    {
        if(s>n || k>maxiK)return ;
        if(k==maxiK and s==n)
        {
            ans.push_back(temp);
            return ;
        }
        for(int i=curr;i<=9;i++)
        {
            temp.push_back(i);
            recu(k+1,i+1,s+i,n,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        maxiK=k;
        vector<int>temp;
        recu(0,1,0,n,temp);
        return ans;
    }
};