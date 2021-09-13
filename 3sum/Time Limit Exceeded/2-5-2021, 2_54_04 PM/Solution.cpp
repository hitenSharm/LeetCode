// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vect;
        unordered_map<int,int>ump;
        int n=nums.size();
        for(int i=0;i<n;i++){ 
            ump[nums[i]]++;            
        }
        map<vector<int>, int>chkVis;
        for(int i=0;i<n;i++){ 
            int toFind=(-1*nums[i]);
            ump[nums[i]]--;
            for(int j=0;j<n;j++){            
                if(i==j)
                    continue;
                else{ 
                    ump[nums[j]]--;                    
                    if(ump.find(toFind-nums[j])!=ump.end()){
                      if(ump[toFind-nums[j]]!=0){ 
                      vector<int>temp;
                           //cout<<toFind<<"\n";
                      temp.push_back(nums[i]);
                      temp.push_back(nums[j]);                      
                      temp.push_back(toFind-nums[j]);
                      //cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<"\n";
                      sort(temp.begin(),temp.end());                      
                      if(chkVis.find(temp) == chkVis.end()){                           
                        chkVis[temp]=1;
                        vect.push_back(temp);
                      }
                          
                      }
                        
                    }
                    ump[nums[j]]++;
                }
                
            }
            ump[nums[i]]++;
            
        }
        return vect;
    }
};