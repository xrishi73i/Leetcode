class Solution {
public:
void f(string &digits,map<char,string> &k,int idx,string &path,vector<string> &ans){
    if(idx==digits.size()){
        ans.push_back(path);
        return;
    }
    
    char digit = digits[idx];
    string choices = k[digit];
    for(auto c : choices){
        path.push_back(c);
        f(digits,k,idx+1,path,ans);
        path.pop_back();
    }
    
}

    vector<string> letterCombinations(string digits) {
    map<char,string> k;
    k['2'] = "abc";
    k['3'] = "def";
    k['4'] = "ghi";
    k['5'] = "jkl";
    k['6'] = "mno";
    k['7'] = "pqrs";
    k['8'] = "tuv";
    k['9'] = "wxyz";
    
    string path;
    vector<string>ans;
    f(digits,k,0,path,ans);
    return ans;
    }

};