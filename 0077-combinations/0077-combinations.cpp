class Solution {
public:
    void solve(vector<int>&v,vector<vector<int>>&ans,int start,int n,int k){
        // if(v.size()==k){
        //     ans.push_back(v);
        // }
        if(v.size()==k){
            ans.push_back(v);
            return ;
        }
        
        for(int i=start;i<=n;i++){

            v.push_back(i);
            solve(v,ans,i+1,n,k);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<vector<int>> ans;
        solve(v,ans,1,n,k);
        return ans;
    }
};