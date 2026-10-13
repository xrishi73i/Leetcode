class Solution {
public:
    int lowerbound(vector<int>&nums,int target){
        int l = 0;
        int h = nums.size();
        while(l<h){
            int mid = l + (h-l)/2;
            if(nums[mid] >= target){
                h = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
        int upperbound(vector<int>&nums,int target){
        int l = 0;
        int h = nums.size();
        while(l<h){
            int mid = l + (h-l)/2;
            if(nums[mid] > target){
                h = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int p = lowerbound(nums,target);
        int pp = upperbound(nums,target);
        int idx =0;
        if (p == nums.size() || nums[p] != target) {
            return {-1, -1};
        }
        return {p,pp-1};
    }
};