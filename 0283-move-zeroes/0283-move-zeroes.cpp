class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //fast and slow 
        int slow = 0;
        int val =0;
        for(int i =1;i<nums.size();i++){
            if(nums[slow]==val){
                if(nums[i] != val){
                    swap(nums[slow],nums[i]);
                    slow++;
                }
                
            }else{
                slow++;
            }
            
        }
        
    }
};