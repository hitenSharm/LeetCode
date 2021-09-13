// https://leetcode.com/problems/find-smallest-letter-greater-than-target

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        if( target < letters[0] || target >= letters[n-1] ) {
		return letters[0];
	    }
        int s=0,end=n-1;
        
        while(s<=end)
        {
            int mid=s+end;
            mid=mid/2;
            if(letters[mid]==target)
            { 
                if(letters[mid+1]>target)
                    return letters[mid+1];
        
            }
            if(target<letters[mid])
                end=mid-1;
            if(target>letters[mid])
                s=mid+1;
        }
        return letters[s];
        
        
    }
};