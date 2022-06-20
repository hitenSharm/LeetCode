class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int f1=0,f2=0,f3=0;
        for(int i=0;i<triplets.size();++i)
        {
            if(triplets[i][0]==target[0] and triplets[i][1]<=target[1] and triplets[i][2]<=target[2])f1=1;
            if(triplets[i][0]<=target[0] and triplets[i][1]==target[1] and triplets[i][2]<=target[2])f2=1;//can take as i have a triplet that has 1st value as target
            if(triplets[i][0]<=target[0] and triplets[i][1]<=target[1] and triplets[i][2]==target[2])f3=1;
        }
        if(f1==1 and f2==1 and f3==1)return true;
        //here we just try to find each triplet basically by checking 1 equal and others smaller or equal
        return false;
    }
};