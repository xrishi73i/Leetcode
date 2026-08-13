class Solution {
public:
    void solve(vector<int> &v,vector<vector<int>> &ans,int start,vector<int>& n){
        set<int>s;
        if(v.size()>=2){
             ans.push_back(v);
        } //valid answaer only 2 and greater then 2 needed '
        

        for(int i=start;i<n.size();i++){
            //this for loop take the possible combination , it take 1 ,then 2, then 3, like that 
            if(!v.empty() and n[i]<v.back()){
                continue; // for the empty check , and non decreasing subsequences
            }
            if(s.count(n[i])){
                continue; // repeated number for
            }
            s.insert(n[i]);

            v.push_back(n[i]);
    

            solve(v,ans,i+1,n);
            v.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        // sort(nums.begin(),nums.end());
        solve(v,ans,0,nums);
        return ans;
    }
};