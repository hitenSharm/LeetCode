class Solution {
public:	    
	int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue <double, vector<double>, greater<double>>pq;
		for(int i=0;i<dist.size();++i)
		{
			int t1=dist[i];
			int t2=speed[i];
			double t3=(t1+0.0)/t2;
			pq.push(t3);
		}
		int time=0;
		int cnt=0;
		while(!pq.empty())
		{
			if(pq.top()>time)
			{
				cnt++;
				time++;
				pq.pop();
			}
			else
			return cnt;
		}
		return cnt;
    }
};