class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int ans =0;
        unordered_map<char,int> mp;
        for(int r=0;r<s.length();r++){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
            
        }
        return ans;

    }
};