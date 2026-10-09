class Solution {
public:
    void solve(vector<int>& nums,vector<int>&v,int idx,int &sum){

        if(idx == nums.size()){
            //the whole subset from here'
            int xori =0;
            for(auto it:v){
                xori ^= it;
            }
            sum += xori;

            return ;
        }

        
        v.push_back(nums[idx]);
        solve(nums,v,idx + 1,sum);
        v.pop_back();
        solve(nums,v,idx + 1,sum);

    }
    int subsetXORSum(vector<int>& nums) {
        
        int sum =0;
        vector<int>v;
        solve(nums,v,0,sum);
        return sum;
        
        // int sum =0;

        // for(auto it:ans){
        //     int xori = 0;
        //     for(auto i:it){
        //         xori ^= i;
        //     }
        //     sum += xori;
        // }
        // return sum ;

    }
};