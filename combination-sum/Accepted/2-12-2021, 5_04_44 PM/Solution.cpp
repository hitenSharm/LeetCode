// https://leetcode.com/problems/combination-sum

class Solution {
public:
    
    bool backTrack(vector<int>& candidates,vector<vector<int>>&ans,vector<int>&temp,int target,int curr){ 
        if(target<0){
            return false;
        }
        if(target==0){ 
        
            ans.push_back(temp);
            return true;
        
        }
        for(int i=curr;i<candidates.size();i++){ 
            if(target-candidates[i]>=0){ 
                target=target-candidates[i];
                temp.push_back(candidates[i]);
                backTrack(candidates,ans,temp,target,i);
                target=target+candidates[i];  
                temp.pop_back();
            }          
        } 
        
        return false;
    
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        backTrack(candidates,ans,temp,target,0);
        return ans;
    
    }
};