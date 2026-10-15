class Solution {
public:
    bool can(vector<int>& time, long long totalTrips,long long k)
    {
        long long sum = 0;
        for(int i =0;i<time.size();i++){
            sum += k/(time[i]);
        }
        return sum >= totalTrips;
    }
    long long minimumTime(vector<int>& time, long long totalTrips) {
        long long l = *min_element(time.begin(),time.end());
        long long h = 1LL * (*min_element(time.begin(),time.end())) * totalTrips;
        while(l<h){
            long long mid = l + (h - l)/2;
            if(can(time,totalTrips,mid)){
                h = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};