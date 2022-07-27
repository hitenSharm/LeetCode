class HitCounter {
private:
    vector<int>times;
public:
    HitCounter(){        
    }
    
    void hit(int timestamp) {
        times.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        int ltime=timestamp-300+1;
        if(ltime<0)return times.size();
        int index=-1;
        int l=0,r=times.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(times[m]>=ltime){
                index=m;
                r=m-1;
            }
            else if(times[m]<ltime){
                l=m+1;
            }            
        }
        if(index==-1)return 0;
        return times.size()-index;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */