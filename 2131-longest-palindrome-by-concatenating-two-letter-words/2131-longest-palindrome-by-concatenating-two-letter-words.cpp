class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>ump;
        for(auto i:words)
        {
            ump[i]++;
        }
        int ans=0;
        bool fl=false;
        for(auto it:words)
        {
            string s=it;
            if(ump[s]==0)continue ;
            string rev=s;
            reverse(rev.begin(),rev.end());
            ump[s]--;
            if(ump[rev]>0)
            {
                ans+=(2*s.size());
                ump[rev]--;//2 letter word ka opposite mil gya
                continue ;
            }
            if(rev==s and !fl)
            {
                fl=true;
                ans+=2;//aa ka ab ek aur aa nahi mila so i jst take 1 aa
            }
        }
        return ans;
    }
};