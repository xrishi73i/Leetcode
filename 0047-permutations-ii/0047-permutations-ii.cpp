class Solution {
public:
void solve(vector<int>& v,
               vector<vector<int>>& ans,
               vector<int>& nums,
               vector<bool>& used) {
                set<int>s;
        if(v.size() == nums.size()) {
            ans.push_back(v);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            // Already used in current permutation
            if(used[i]) {
                continue;
            }
            if(s.contains(nums[i])){
                continue;
            }
            s.insert(nums[i]);
            // Choose
            used[i] = true;
            v.push_back(nums[i]);
            solve(v, ans, nums, used);
            // Backtrack
            v.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);
        solve(v, ans, nums, used);
        return ans;
    }
};