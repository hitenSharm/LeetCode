class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        //this question is solved when you play with the data a bit
		//if u keep adding 1 to each value in the array u realise that in the end
		//the pass ratio when adding students is all about how much it changes when we add
		//students, if we can find which index to add to get max change possible at that instance
		//we will get our answer. It does not have to be the minimum ratio one as change decreases as we add 1
		//this is becoz it will eventually lead to 1
		priority_queue<pair<double,int>>pq;
		for(int i=0;i<classes.size();i++)
		{
			int pass=classes[i][0];
            int total=classes[i][1];            
            double growth=(double)(pass+1)/(total+1) - (double)(pass)/(total);
            
			pq.push({growth,i});
		}
		while(extraStudents>0)
		{
			pair<double,int>p=pq.top();
			pq.pop();
			int i=p.second;
			classes[i][0]++;classes[i][1]++;
			int pass=classes[i][0];
            int total=classes[i][1];            
            double growth=(double)(pass+1)/(total+1) - (double)(pass)/(total);
			pq.push({growth,i});            
			extraStudents--;
		}
		double ans=0;
		while(!pq.empty())
		{
            // cout<<pq.top().first<<endl;
			int i=pq.top().second;
            int x=classes[i][0];
            int y=classes[i][1];
            ans+=(double)(x)/(y);
			pq.pop();
		}
		ans=ans/classes.size();
		return ans;
    }
};