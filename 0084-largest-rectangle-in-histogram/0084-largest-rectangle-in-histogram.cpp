class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();

        vector<int> right(n);
        vector<int> left(n);

        stack<int> st;

        // Nearest Smaller Element to the Right
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }

            if(!st.empty())
                right[i] = st.top();
            else
                right[i] = n;

            st.push(i);
        }

        // Clear stack
        while(!st.empty()) {
            st.pop();
        }

        // Nearest Smaller Element to the Left
        for(int i = 0; i < n; i++) {

            while(!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }

            if(!st.empty())
                left[i] = st.top();
            else
                left[i] = -1;

            st.push(i);
        }

        // Calculate maximum area
        int maxi = 0;

        for(int i = 0; i < n; i++) {

            int width = right[i] - left[i] - 1;

            int area = height[i] * width;

            maxi = max(maxi, area);
        }

        return maxi;
    }
};