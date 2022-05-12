class Solution {
public:
	int log_a_to_base_b(int a, int b)
	{
		return log2(a) / log2(b);
	}
	bool recu(int curr,int n,vector<int>& dp)
	{        
		n=n-dp[curr];        
		if(n==0)return true;
        if(curr==0)return false;
		curr=min(log_a_to_base_b(n,3),curr-1);
		if(recu(curr,n,dp))return true;
		return false;
	}
    bool checkPowersOfThree(int n) {
        vector<int>dp3(15);
		dp3[0]=1;
        dp3[1]=3;
		int h=log_a_to_base_b(n,3);
		for(int i=2;i<=h;i++)
		{
			dp3[i]=dp3[i-1]*3;
		}		
		for(int i=h;i>=0;i--)
		{
			if(recu(i,n,dp3))return true;			
		}
		return false;
    }
};