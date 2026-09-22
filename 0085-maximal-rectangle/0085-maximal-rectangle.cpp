class Solution {
public:

    int maxArea(vector<int>& height) {

        int n = height.size();

        vector<int> right(n);
        vector<int> left(n);

        stack<int> st;

        // NSE from the right
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }

            if(st.empty()) {
                right[i] = n;
            }
            else {
                right[i] = st.top();
            }

            st.push(i);
        }

        // Clear stack
        while(!st.empty()) {
            st.pop();
        }

        // NSE from the left
        for(int i = 0; i < n; i++) {

            while(!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }

            if(st.empty()) {
                left[i] = -1;
            }
            else {
                left[i] = st.top();
            }

            st.push(i);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {

            int width = right[i] - left[i] - 1;

            int area = height[i] * width;

            ans = max(ans, area);
        }

        return ans;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> v(m, 0);

        int ans = 0;

        for(int i = 0; i < n; i++) {

            // Build histogram for current row
            for(int j = 0; j < m; j++) {

                if(matrix[i][j] == '1') {
                    v[j]++;
                }
                else {
                    v[j] = 0;
                }
            }

            // Largest rectangle in current histogram
            ans = max(ans, maxArea(v));
        }

        return ans;
    }
};