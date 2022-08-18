class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //montonic stack approach
        //observation: every bar can be a height for some rect.
        stack<int>st;
        unordered_map<int, int>prefix;
        unordered_map<int, int>suffix;
        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        for (int i = 1; i < heights.size(); i++)
        {
            while (!st.empty() and heights[st.top()] > heights[i])
            {
                suffix[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty())
            st.pop();

        for (int i = heights.size() - 2; i >= 0; i--)
        {
            while (!st.empty() and heights[st.top()] > heights[i])
            {
                prefix[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        int ans = 0;
        for (int i = 1; i < heights.size() - 1; i++)
        {                      
            ans = max(ans, heights[i] * (suffix[i] - prefix[i]-1));
        }
        return ans;
    }
};