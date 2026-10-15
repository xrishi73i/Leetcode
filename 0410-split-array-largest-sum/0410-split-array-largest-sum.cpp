class Solution {
public:
    bool can(vector<int>& nums, int k,int mid){
        long long sumi = 0;
        int count =1;
        for(int i=0;i<nums.size();i++){
            if(sumi + nums[i] > mid){
                count++;
                sumi = nums[i]; 
            }else{
                sumi += nums[i]; //previous counter , 
            }
        }
        return count <=k; // exactly want this one
    } 
    int splitArray(vector<int>& nums, int k) {
        long long l = *max_element(nums.begin(),nums.end());
        long long h = accumulate(nums.begin(),nums.end(),0LL);
        while(l<h){
            int mid = l + (h-l)/2;
            if(can(nums, k, mid)){
                
                h = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};