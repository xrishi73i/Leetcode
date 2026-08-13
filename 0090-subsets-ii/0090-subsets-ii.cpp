class Solution {
public:
    void solve(vector<int> &v,vector<vector<int>> &ans,int start,vector<int>& n){
        ans.push_back(v);
        for(int i=start;i<n.size();i++){

            if(i>start and n[i]==n[i-1]){
                continue;
            }
            v.push_back(n[i]);
            solve(v,ans,i+1,n);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(v,ans,0,nums);
        return ans;
    }
};