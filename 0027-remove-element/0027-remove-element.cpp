class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l =0;
        int r = nums.size()-1;
        while(l<=r){
            if(nums[l]==val){
                if(nums[l]==nums[r]){
                    r--;
                }
                else{
                    swap(nums[l],nums[r]);
                    l++;
                    r--;
                }
            }
            else{
                l++;
            }
        }
        return l;
    }
};