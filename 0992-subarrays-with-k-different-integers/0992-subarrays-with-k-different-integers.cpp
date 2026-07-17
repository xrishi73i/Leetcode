class Solution {
public:
public: 
    int check1(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int,int> mp;
        int l =0;
        int ans =0;
        for(int r =0;r<n;r++){
            // s.insert(nums[r]);//inset
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                // s.erase(nums[r]);
                
                l++;
            }
            ans+= r-l+1;

            
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return check1(nums,k) - check1(nums,k-1);
    }
};