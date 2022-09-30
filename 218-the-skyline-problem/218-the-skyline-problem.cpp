class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> walls;                  // first: x, second: height
        vector<vector<int>>ans;
        for (auto b : buildings) {
            // push in left / right walls
            // let left wall has negative height to ensure left wall goes to multiset first if with same 'x' as right wall
            walls.push_back(make_pair(b[0], -b[2]));
            walls.push_back(make_pair(b[1], b[2]));
        }
        sort(walls.begin(), walls.end());                   // sort walls
        
        multiset<int> leftWallHeights = {0}; 
        int top=0;
        for(auto i:walls)
        {
            if(i.second<0)
            {
                //start point
                leftWallHeights.insert(-i.second);
            }
            else
            {
                //end point
                leftWallHeights.erase(leftWallHeights.find(i.second));
            }
            
            if(*leftWallHeights.rbegin()!=top) //as we can get the same ht end
            {
                top=*leftWallHeights.rbegin();//update new top
                ans.push_back({i.first,top});
            }
        }
        return ans;
    }
};