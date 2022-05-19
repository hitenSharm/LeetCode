class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int m1=arr.size()/4;
		int m2=arr.size()/2;
		int m3=0.75*arr.size();
		vector<int>c{arr[m1],arr[m2],arr[m3]};
		int d=0,ans;
		for(int i=0;i<c.size();i++)
		{
			int u=upper_bound(arr.begin(),arr.end(),c[i])-arr.begin();
			int l=lower_bound(arr.begin(),arr.end(),c[i])-arr.begin();
			if(d<u-l)
			{
				d=u-l;
				ans=c[i];
			}
		}
		return ans;
    }
};