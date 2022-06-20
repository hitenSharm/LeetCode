class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        special.push_back(top+1);
        int i=bottom,s=0;
        int ans=0;
        while(bottom<top)
        {
            bottom+=(special[s]-bottom);
            ans=max(ans,bottom-i);
            i=special[s]+1;
            bottom=i;
            s++;
        }
        return ans;
    }
};