class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> answer(n, 0);

        for (int i = 0; i < n; i++) {
            while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int j = st.top();
                st.pop();
                answer[j] = i - j;
            }
            st.push(i);
        }
        return answer;
    }
};