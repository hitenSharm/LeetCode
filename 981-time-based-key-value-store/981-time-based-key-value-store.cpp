class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>ump;
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        ump[key].push_back({ timestamp,value });
    }

    string get(string key, int timestamp) {
        if(ump.find(key)==ump.end())return "";
        int l = 0;
        int r = ump[key].size()-1;
        vector < pair<int, string>>& arr = ump[key];
        int ans=arr.size()-1;
        if(arr[0].first>timestamp)return "";
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (arr[m].first <= timestamp) {
                ans=m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
       
        return arr[ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */