class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans=0;
        int i=0;
        while(i<seats.size() and seats[i]==0)
        {
            i++;
        }
        ans=max(ans,i);
        while(i<seats.size())
        {
            int len=0;
            int ocnt=0;
            while(i<seats.size() and ocnt<2)
            {
                if(seats[i]==1)ocnt++;
                
                i++;len++;
            }
            i--;
            if(ocnt==2)
            {
                if(len%2==0)
                len=(len/2)-1;
                else
                len=len/2;
                ans=max(ans,len);
            }
            else
            ans=max(ans,len-1);
            if(i==seats.size()-1)break;
        }
        return ans;
    }
};