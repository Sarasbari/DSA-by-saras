class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 1)
            return heights[0];
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        vector<int> st;
        int maxarea = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.back()]) {
                int h = heights[st.back()];
                st.pop_back();
                int w = i - st.back() - 1;

                maxarea = max(maxarea, h * w);
            }
            st.push_back(i);
        }
        return maxarea;
    }
};