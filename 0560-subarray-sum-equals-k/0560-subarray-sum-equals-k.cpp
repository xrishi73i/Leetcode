class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum =0;
        int num =0;

        unordered_map<int,int> mp;
        mp[0] = 1;
        for(auto &it :nums){
            sum += it;
            if(mp.count(sum-k)){
               num += mp[sum-k];

            }
            mp[sum]++;
        }
        return num;
    }
};