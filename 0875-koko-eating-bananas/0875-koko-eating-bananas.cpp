class Solution {
public:
    bool can(vector<int>& piles , int h ,int k){
        long long hour = 0;
        for(int i =0;i<piles.size();i++){
            hour += (piles[i]+k-1)/k;
        }
        return hour<=h;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //writing the binary search 
        int l = 1;
        int ho = *max_element(piles.begin(),piles.end());
        while(l<ho){
            int mid = l + (ho - l)/2;
            if(can(piles,h,mid)){
                ho = mid ;
                
            }else{
                l = mid+1;
            }
        }
        return l ;
    }
};