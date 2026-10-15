class Solution {
public:
    bool can(vector<int>& weights, int days,int cap){
        int load =0;
        int dayUsed = 1;//mini one day , will be there
        for(int i=0;i<weights.size();i++){
            if(load + weights[i] > cap){
                dayUsed++;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return dayUsed <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int h = accumulate(weights.begin(),weights.end(),0);
        while(l<h){
            int mid = l + (h-l)/2;
            if(can(weights,days,mid)){
                h = mid; // try smaller
            }
            else{
                l = mid + 1; //try largers , if fails
            }
        }
        return l;
    }
};