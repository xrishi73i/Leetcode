class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int l =0;
        int r =t.size()-1;
        if(s.size() != t.size()){
            return false;
        }
        while(l<=r){
            if(s[l]==t[l]){
                l++;
            }else
            return false;
        }
        return true;
    }
};