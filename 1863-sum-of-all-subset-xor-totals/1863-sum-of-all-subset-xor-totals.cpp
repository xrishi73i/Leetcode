class Solution {
public:
    void solve(vector<int>& nums,vector<int>&v,vector<vector<int>>&ans,int idx){

        if(idx == nums.size()){
            ans.push_back(v);
            return ;
        }

        
        v.push_back(nums[idx]);
        solve(nums,v,ans,idx + 1);
        v.pop_back();
        solve(nums,v,ans,idx + 1);

    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(nums,v,ans,0);
        
        int sum =0;

        for(auto it:ans){
            int xori = 0;
            for(auto i:it){
                xori ^= i;
            }
            sum += xori;
        }
        return sum ;

    }
};