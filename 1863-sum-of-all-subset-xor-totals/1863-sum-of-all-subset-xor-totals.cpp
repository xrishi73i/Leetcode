
class Solution {
public:
    void solve(vector<int>& nums, int idx,
               int currXor, int& sum) {

        if (idx == nums.size()) {
            sum += currXor;
            return;
        }

        // PICK
        solve(nums, idx + 1, currXor ^ nums[idx], sum);

        // NOT PICK
        solve(nums, idx + 1, currXor, sum);
    }

    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        solve(nums, 0, 0, sum);
        return sum;
    }
};
