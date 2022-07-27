class TopVotedCandidate {
private:
    unordered_map<int,int>ump;
    vector<int>time;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        time=times;
        int maxCnt=0;
        int maxEle;
        unordered_map<int,int>freq;
        for(int i=0;i<persons.size();i++)
        {
            freq[persons[i]]++;
            if(maxCnt<=freq[persons[i]])
            {
                maxCnt=freq[persons[i]];
                maxEle=persons[i];
            }
            ump[i]=maxEle;
        }        
    }
    
    int getIndex(int x)
    {
        int l=0,r=time.size()-1;
        int ans=-1;
        while(l<=r)
        {
            int m = l + (r-l)/2;
            if(time[m]>x){
                r=m-1;
            }
            else if(time[m]<x){
                ans=m;
                l=m+1;
            }
            else
                return m;
        }
        return ans;
    }
    
    int q(int t) {
        int n=getIndex(t);                
        return ump[n];        
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */