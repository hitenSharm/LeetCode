class SnapshotArray {
public:    
	unordered_map<int,unordered_map<int,int>>ump;
	int cnt=0;
	SnapshotArray(int length) {        			
    }

    void set(int index, int val) {
		unordered_map<int,int>& t=ump[cnt];
		t[index]=val;
    }
    
    int snap() {
        cnt++;
        ump[cnt]=ump[cnt-1];
		return cnt-1;
    }
    
    int get(int index, int snap_id) {
        unordered_map<int,int>& t=ump[snap_id];
		return t[index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */