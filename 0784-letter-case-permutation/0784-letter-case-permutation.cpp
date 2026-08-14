class Solution {
public:
    void solve(vector<string>&ans,string s,int idx){
              if(idx == s.size()) {
            ans.push_back(s);
            return;
        }
        if(isdigit(s[idx])){
            solve(ans,s,idx+1);
        }
        else{
            s[idx] = tolower(s[idx]);
            solve(ans,s,idx+1);
            s[idx] = toupper(s[idx]);
            solve(ans,s,idx+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        
        vector<string> ans;

        solve(ans,s,0);

        return ans;
    }
};