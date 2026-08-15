class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x =0;
        bool hasNonZero = false;
        for( auto &it :nums){
            x ^= it;
            if(it !=0){
                hasNonZero = true;
            }
        }
        if(x!=0){
            return nums.size();
        }
        if(hasNonZero){
            return nums.size()-1;
        }
        return 0;

    }
};