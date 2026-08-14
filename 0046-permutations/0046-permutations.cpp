class Solution {
public:
    void solve(vector<int>&v, vector<vector<int>>&ans,vector<int>& nums,vector<bool>&used){
        if( v.size()==nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++){
            //market the bool 
            if(used[i]){
                continue;
            }
            used[i] =true;
            v.push_back(nums[i]);
            solve(v,ans,nums,used);
            v.pop_back();
            used[i] = false;

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>v;
        vector<vector<int>>ans;
        vector<bool>used(nums.size(),false);
        solve(v,ans,nums,used);
        return ans;
    }
};