class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        //max heap        
        stations.push_back({ target,0 });

        priority_queue<int>pq;
        int ans = 0;
        int fuel = startFuel;
        int last = 0;
        for (int i = 0; i < stations.size(); i++)
        {
            while (stations[i][0] > fuel + last)//cant cover
            {
                if (pq.size() == 0)return -1;
                fuel += pq.top();
                pq.pop();
                ans++;
            }

            pq.push(stations[i][1]);

            fuel -= (stations[i][0] - last);
            last = stations[i][0];
            if (last == target)return ans;
        }
        return -1;
    }
};