class Solution {
public:
    bool can(vector<int>& pos , long long m , long long mid){
        long long count = 1;
        long long  laspos = pos[0];
        for(int i=1;i<pos.size();i++){
            if((pos[i] - laspos)>=mid){
                count++;
                laspos = pos[i];
            }
        }
        return count >= m; /// if all placed return true ;
    }
    int maxDistance(vector<int>& position, long long m) {
        sort(position.begin(),position.end());
        long long l = 1;
        long long h = position.back()- position.front();
        while(l<h){
            long long mid = l + (h-l+1)/2;  // for maximum we roundoff , h-l+1
            if(can(position,m, mid)){
                l = mid;
            }else{
                h = mid -1;
            }
        }
        return l;

    }
};