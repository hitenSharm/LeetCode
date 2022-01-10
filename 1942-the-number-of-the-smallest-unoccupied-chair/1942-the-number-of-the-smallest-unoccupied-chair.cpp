class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int t=times[targetFriend][0];
        typedef pair<int, int> p;
        priority_queue<p, vector<p>, greater<p>> pq;
        sort(times.begin(),times.end());
        priority_queue <int, vector<int>, greater<int> > seats;
        for(int i=times.size()-1;i>=0;--i)seats.push(i);
        
        for(int i=0;i<times.size();i++)
        {
            while(!pq.empty() and pq.top().first<=times[i][0])
            {
                seats.push(pq.top().second);
                pq.pop();
            }
            pq.push({times[i][1],seats.top()});
            if(t==times[i][0])return seats.top();
            seats.pop();
        }
        return 0;
    }
};