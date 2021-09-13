// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi[height.size()];
        int mini[height.size()];
        vector< pair <int,int> > vect; 
        for(int i=0;i<height.size();i++){
            vect.push_back( make_pair(height[i],i+1));
        }
        sort(vect.begin(), vect.end());
        int n=height.size();
        
        for(int i=n-1;i>0;i--){ 
            if(i==n-1){ 
            maxi[i]=vect[i].second;
            mini[i]=vect[i].second;
            }
            else{
                maxi[i]=max(maxi[i+1],vect[i].second);
            mini[i]=min(mini[i+1],vect[i].second);
            }
            cout<<maxi[i]<<" "<<mini[i]<<endl;
        }        
        int ans=0;
        for(int i=0;i<n-1;i++){ 
            int currH=vect[i].first;
            int currB=max(abs(vect[i].second-maxi[i+1]),abs(vect[i].second-mini[i+1]));
            //cout<<abs(vect[i].second-maxi[i+1])<<" "<<abs(vect[i].second-mini[i+1])<<endl;
            ans=max(ans,(currH*currB));
        }
        return ans;
    }
};