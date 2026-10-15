class Solution {
public:
    bool can(vector<int>& nums, int threshold,int k){
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum += (nums[i] + k - 1)/k;
        }
        return sum <=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l =1;
        int h =  *max_element(nums.begin(),nums.end());
        while(l<h){
            int mid = l + (h-l)/2;
            if(can(nums,threshold,mid)){
                h = mid;
                
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};