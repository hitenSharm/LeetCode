class Solution {
public:
    
    int solver(vector<int>& ranges,int& n)
    {
        vector<int>jumps(n+1,0);
        for(int i=0;i<ranges.size();i++)
        {
            int l=max(0,i-ranges[i]);
            int r=min(n,i+ranges[i]);
            jumps[l]=max(jumps[l],r-l); // r-l means i can go from l to jumps[l] + r-l 
            //r-l means how furtehr i can jump in the array or how further can i get a range of opened taps filling water in the array
        }   
        int currentEnd=0;
        int furthestJump=0;
        int ans=0;
        for(int i=0;i<jumps.size()-1;i++)
        {
            if(i>furthestJump)return -1; //no more jumping possible, cant be reached
            //furthestJump shud always be ahead of i as i shud always be moving forward
            furthestJump=max(furthestJump,i+jumps[i]);
            if(i==currentEnd)
            {
                ans++;
                currentEnd=furthestJump;
            }
        }
        return furthestJump>=n ? ans : -1;   //edge case for n-1 index     
    }
    
    
    
    int minTaps(int& n, vector<int>& ranges) {
        return solver(ranges,n);
        // vector<vector<int>>arr;
        // for(int i=0;i<ranges.size();i++)
        // {
        //     int st=max(0,i-ranges[i]);
        //     int en=min(n,i+ranges[i]);            
        //     arr.push_back({st,en});
        // }
        // sort(arr.begin(),arr.end());
        // int taps=0;
        // int mini=0;//how further we can go //mini is the value which hsa to be satisfied
        // int index=0;
        // while(mini<n)
        // {
        //     int maxi=0;
        //     while(index<n)
        //     {
        //         if(arr[index][0]>mini)break ;//out of range
        //         //in range
        //         maxi=max(maxi,arr[index][1]);
        //         index++;
        //     }
        //     if(mini==maxi)return -1;
        //     taps++;
        //     mini=maxi;                
        // }
        // return taps;
    // https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/discuss/486517/C%2B%2B-O(n)-no-sort-similar-to-Jump-Game-II
        
    }
};