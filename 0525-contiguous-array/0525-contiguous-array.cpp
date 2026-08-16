class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //unorderd map creation , in this
        //count of zero and one will be same 
        //transform the array fully 
        // -> 0 (-1)
        // -> 1 (1)
        unordered_map<int,int>mp;
        int sum =0;
        int ans =0;
        int num =0;
        vector<int>p(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                p[i]=-1;
            }else{
                p[i]=1;
            }
        }
        for(int i=0;i<nums.size();i++){
            sum += p[i];
            if(sum==0){
                ans = max(ans,i+1);
            }
            if(mp.count(sum)){
                ans = max(ans,i - mp[sum]);
            }
            if(!mp.count(sum)){
                mp[sum]= i;//for the index
            }
        }
        return ans;
   
    }
};