class Solution {
public:
    int countElements(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        int count =0;
        for(auto it:nums){
            if(it <maxi and it >mini){
                count++;
            }
        }
        return count;
    }
};