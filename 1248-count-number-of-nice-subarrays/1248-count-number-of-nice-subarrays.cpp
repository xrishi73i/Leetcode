    int check1(vector<int>& nums, int k) {
        
        int count =0;
        int l = 0;
        int ans =0;
        for(int r=0;r<nums.size();r++){
            if(1&nums[r]){
                count++;
            }
            while(count>k){
                if(1&nums[l]){
                    count--;
                }
                l++;

            }
            ans+=r-l+1;
            


        }
        return ans;  
    }
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return check1(nums,k) - check1(nums,k-1);

    }
};