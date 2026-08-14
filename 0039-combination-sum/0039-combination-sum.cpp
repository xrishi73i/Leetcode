class Solution {
public:
    void solve(vector<int>&v, vector<vector<int>>&ans,int start ,int sum, vector<int>&nums,int target){
        if(sum == target ){
            ans.push_back(v);
            return;
        }


        for(int i= start;i<nums.size();i++){
            if(sum + nums[i]>target){
                continue;
            }
            v.push_back(nums[i]);

            solve(v,ans,i,sum+nums[i],nums,target);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        solve(v,ans,0,0,candidates,target);
        return ans;
    }
};