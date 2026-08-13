class Solution {
public:
    void solve(vector<int>&v,vector<vector<int>>&ans,int start,int k,int n,int sum){
        if(sum ==n && v.size() ==k){
            ans.push_back(v);
            return;
        }
        for(int i=start;i<=9;i++){
            v.push_back(i);
            solve(v,ans,i+1,k,n,sum + i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        vector<vector<int>> ans;
        solve(v,ans,1,k,n,0);
        return ans;
    }
};