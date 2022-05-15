class Solution {
public:

	void swapper(vector<char>& arr)
	{
		int i=arr.size()-1,j=arr.size()-1;
		while(i-1>=0 and j>=0)
		{
			while(i-1>=0 and arr[i]!='#' and arr[i]!='*')
			i--;
			while(arr[i]!='*' and j>=0 and arr[j]!='.')
			j--;
			if(i<j and arr[i]!='*')swap(arr[i],arr[j]);
			else
			{
				i--;
				j=i;
			}
		}
	}

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {                
        for(int i=0;i<box.size();i++)
		{
			swapper(box[i]);
		}        
		vector<vector<char>> v(box[0].size(), vector<char> (box.size(), '.'));
		int i=box.size()-1,j=0;
		while(i>=0)
		{
			for(int k=0;k<box[0].size();k++)
			{
				v[k][j]=box[i][k];
			}
			j++;i--;
		}
		return v;
    }
};