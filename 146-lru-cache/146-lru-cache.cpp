    class LRUCache {
        
    private:
        list<pair<int,int>>cache;
        unordered_map<int,list<pair<int,int>> :: iterator>ump;
        int cap;
    public:
    
    void putFront(int k,int v)
    {        
        cache.erase(ump[k]);//erase old posi from dll
        cache.push_front({k,v});//move to front of list
        ump[k]=cache.begin();//update new value
    }
        
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(ump.find(key)==ump.end())return -1;
        int value=(*ump[key]).second;
        putFront(key,value);
        return value;
    }
    
    void put(int key, int value) {
        //already in list
        if(ump.find(key)!=ump.end()){
            //put in front            
            putFront(key,value);
        }else{
            //not in list
            cache.push_front({key,value});
            ump[key]=cache.begin();
            if(ump.size()>cap){
                ump.erase(cache.back().first);//erase last element using key
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