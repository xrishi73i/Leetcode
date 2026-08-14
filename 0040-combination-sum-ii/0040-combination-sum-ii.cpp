class Solution {
public:
    void solve(vector<int>&v, vector<vector<int>>&ans,int start,int sum,vector<int>& nums, int target){
        set<int> s;
        if(sum == target){
            ans.push_back(v);
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(sum + nums[i] >target){
                continue;
            }
            if(i > start && nums[i] == nums[i-1])
             continue;
            v.push_back(nums[i]);
            solve(v,ans,i+1,sum+nums[i],nums,target);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        solve(v,ans,0,0,candidates,target);
        return ans;
    }
};