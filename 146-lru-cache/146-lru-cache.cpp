class LRUCache {
public:
	list<pair<int,int>>cache;
	unordered_map<int,list<pair<int,int>> :: iterator>hash;

	void makeMostRecent(int key,int value)
	{
		cache.erase(hash[key]);
		cache.push_front({key,value});
		hash[key]=cache.begin();
	}
	int cap;	
    LRUCache(int capacity) {
        cap=capacity;
    }
     
    int get(int key) {
        if(hash.find(key)!=hash.end())
        {
        	int val=(*hash[key]).second;
        	makeMostRecent(key,val);
        	return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hash.find(key)!=hash.end())
        {
        	makeMostRecent(key,value);
        }
        else
        {
        	cache.push_front({key,value});
        	hash[key]=cache.begin();        	
        	if(hash.size()>cap)
        	{
        		hash.erase(cache.back().first);//last element key
        		cache.pop_back();
        	}
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */