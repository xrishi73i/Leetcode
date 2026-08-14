class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        if(ch == 'a'||  ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int l =0;
        int ans =0;
        int count =0;
        for(int r=0;r<s.length();r++){
            if(isVowel(s[r])){
                count++;
                }
            if(r-l+1 >k){
                
                if(isVowel(s[l])){
                    count--;

                }
                l++;
                
            }
            ans = max(ans, count);
        }
        return ans;
    }
};