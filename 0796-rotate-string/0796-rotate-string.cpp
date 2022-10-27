class Solution {
public:
    bool rotateString(string A, string B) {
        //aacdda
        //acddaa
        //cddaaa
        
        //o(n*m) method is to add s to itslef and find common in s and goal
        return A.size() == B.size() && (A + A).find(B) != string::npos;
        
    }
};