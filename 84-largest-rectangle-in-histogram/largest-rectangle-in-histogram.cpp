class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();

        stack<int> stk;
        int ans= 0;
        for(int i=0; i <= n; i++){
            int currHeight = (i==n) ? 0: heights[i];

            while(!stk.empty() && heights[stk.top()] >= currHeight ){
                int h = heights[stk.top()];
                stk.pop();

                int left = (stk.empty()) ? -1: stk.top();
                int right = i;

                int width = right - left -1;
                ans = max(ans, width*h);
            }
            stk.push(i);
        }
        return ans; 
    }
};