class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        vector<int>diff(n+2,0);
        for(auto &it:bookings){
            int l = it[0];
            int r = it[1];
            int seat = it[2];

            diff[l] += seat;
            diff[r+1] -= seat;
        }
        //prefix-sum 
        int sum =0;
        vector<int>nums(n);
        for(int i=1;i<=n;i++){
            sum += diff[i];
            nums[i-1]=sum;
        }
        return nums;

    }
};