class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            if(i>0 and nums[i] == nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(j>i+1 and nums[j] == nums[j-1]){
                continue;
            }
                int l = j+1;
                int r = n-1;
                while(l<r){
                    vector<int>vin;
                    long long sum = 1LL *nums[i] +nums[j] +nums[l] + nums[r];
                    if(sum==(long long)target){
                        vin.push_back(nums[i]);
                        vin.push_back(nums[j]);
                        vin.push_back(nums[l]);
                        vin.push_back(nums[r]);
                        v.push_back(vin);

                        l++;
                        r--;
                        while(l<r and nums[l] == nums[l-1]){
                            l++;
                        }
                        while(l<r and nums[r] == nums[r+1]){
                            r--;
                        }
                    }
                    else if(sum<(long long)target){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }
        return v;
    }
};