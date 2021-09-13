// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    
    bool backtrack(unordered_map<char, string>phoneMap,vector<string> &ans,string temp ,string digits,int curr){
        if(curr>=digits.length()){ 
            ans.push_back(temp);
            return true;
        }
        //get candidates to start tracking from
        string candidates=phoneMap[digits[curr]];
        for(int i=0;i<candidates.length();i++){
            //make a move
            temp=temp+candidates[i];
            //move forward
            backtrack(phoneMap,ans,temp,digits,curr+1);
            //undo move
            temp.pop_back();
        }
        return false;
    }
    
    
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
            return vector<string>();
        unordered_map<char, string>phoneMap = { {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},
		{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };
        
        vector<string>ans;
        string temp;
        int currIndex=0;
        backtrack(phoneMap,ans,temp,digits,currIndex);
        return ans;
    }
};