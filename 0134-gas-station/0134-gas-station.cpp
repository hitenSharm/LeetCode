class Solution {
public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c) {
        if(accumulate(g.begin(),g.end(),0)-accumulate(c.begin(),c.end(),0)<0)return -1;
        //har point se all i wanna do is see if i can reach the end
        //if i can reach the end of the array of differences i have that as answer
        //as when i do the sum check first, it means from any index, the sum of a half(i to end) and sum of other(0 to i-1) is always valid
        //so just chek if i can go from i to end
        //if i cant go from i to end and it becomes invalid at some j<end that means no answer between i and j either!
        
        int idx;
        int ts=0;
        int fl=0;
        for(int i=0;i<g.size();i++)
        {
            ts+=(g[i]-c[i]);
            if(ts<0)
            {
                ts=0;
                fl=0;
            }
            else if(ts>=0 and fl==0){
                idx=i;
                fl=1;
            }
        }
        return idx;        
    }
};