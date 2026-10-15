class Solution {
public:

    bool can(vector<int>& candies, long long k,long long mid){
     
        long long count =0;
        for(int i=0;i<candies.size();i++){
            count += candies[i]/mid;
        }
        return count >=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long l = 1;
        long long h = *max_element(candies.begin(),candies.end());
        if(accumulate(candies.begin(),candies.end(),0LL) < k){
            return 0;
        }
        while(l<h){
            long long mid = l + (h - l+1)/2;
            if(can(candies,k,mid)){
                l = mid;
            }else{
                 h = mid -1;
            }
        }
        return l;
    }
};