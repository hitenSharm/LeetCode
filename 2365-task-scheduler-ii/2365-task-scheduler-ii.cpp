class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long, long long>ump;
        long long days = 0;
        int i = 0;
        while (i < tasks.size())
        {
            days++;
            if (ump.find(tasks[i]) == ump.end() || ump[tasks[i]] + space < days)
            {
                ump[tasks[i]] = days;
            }
            else
            {
                days = ump[tasks[i]] + space + 1;
                ump[tasks[i]] = days;
            }
            i++;
        }
        return days;
    }
};