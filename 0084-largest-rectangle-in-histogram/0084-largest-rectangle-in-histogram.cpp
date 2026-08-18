class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxarea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currentheight = (i == n) ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] > currentheight) {
                int height = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                int width = right - left - 1;
                maxarea = max(maxarea, height * width);
            }
            if (i < n)
                st.push(i);
        }
        return maxarea;
    }
};