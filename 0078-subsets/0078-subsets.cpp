class Solution {
public:

    void f(vector<vector<int>>& ans,
           vector<int>& ds,
           int i,
           int n,
           vector<int>& nums) {

        // Base Case
        if (i == n) {
            ans.push_back(ds);
            return;
        }

        // Take
        ds.push_back(nums[i]);
        f(ans, ds, i + 1, n, nums);
        ds.pop_back();

        // Don't Take
        f(ans, ds, i + 1, n, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;

        int n = nums.size();

        f(ans, ds, 0, n, nums);

        return ans;
    }
};