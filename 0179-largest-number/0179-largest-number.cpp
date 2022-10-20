class Solution {
public:
    
    //how to compare which of the 2 combninations give larger
    //9,98 -> 998 or 989. JUST make BOTH!
    bool isSmaller(string s1,string s2)
    {
        string t1=s1+s2;
        string t2=s2+s1;
        //cout<<t1<<" "<<t2<<endl;
        for(int i=0;i<t1.size();i++)
        {
            if(t1[i]==t2[i])continue ;
            //cout<<t1[i]<<" "<<t2[i]<<endl;
            if((t1[i]-'0') < (t2[i]-'0'))return true;
            if((t1[i]-'0') > (t2[i]-'0'))return false;
        }
        return false;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        for(auto i:nums)
        {
            arr.push_back(to_string(i));
        }
        for(int i=0;i<arr.size()-1;i++)
        {
            for(int j=0;j<arr.size()-1;j++)
            {
                if(isSmaller(arr[j],arr[j+1]))//means j is smaller than j+1 (we need descending)
                {
                    swap(arr[j],arr[j+1]);
                }
            }
        }
        string ans="";
        for(auto i:arr)ans+=i;
        int idx=0;
        while(idx<ans.size()-1 and ans[idx]=='0')idx++;
        return ans.substr(idx);        
    }
};