class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l =0;
        int ans =0;
        int sum =0;
        int count =0;
        for(int r=0;r<arr.size();r++){
            int sum = sum + arr[r];
            if(r-l+1 ==k){
                if(sum >=k * threshold){
                    count++;
                }
                sum -= arr[l];
                l++;
                
                
            }
            ans = max(ans, count);
        }
        return ans;
    }
};