class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int i=0,j=0;
        char validate[5]={'a','e','i','o','u'};
        int len=0;
        while(j<word.size())
        {
            if(word[j]=='a')
            {
                i=j;
                int start=0;                
                while((start<5 and word[i]==validate[start]) || (start+1<5 and word[i]==validate[start+1]))
                {
                    if(start+1<5 and word[i]==validate[start+1])start++;
                    i++;
                }
                //cout<<i<<"  i and j "<<j<<endl;
                if(word[i-1]=='u')len=max(len,i-j);
                j=i;
            }    
            else
                j++;
        }
        return len;
    }
};