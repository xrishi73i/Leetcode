class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int closed = nums[0]+ nums[1]+nums[2];
        for(int i=0;i<n;i++){
            int l = i+1;
            int r = n-1;
            
            while(l<r){
                
                int sum = nums[i]+nums[l]+nums[r];
                                if(sum==target){
                     return sum;
                }
                else if(  abs(sum - target) < abs(closed -target)){
                    closed = sum;
              
                }

                else if(sum<target){
                    l++;
                }else{
                    r--;
                }

            }
            
        }
        return closed;
    }
};