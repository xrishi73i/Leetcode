class Solution {
public:
public:
    int check(vector<int> &position,int k ,int dist){
        int painter = 1;
        int last = position[0];
        for(int r=1;r<position.size();r++){
            if(position[r]-last>=dist){
                last = position[r];
                painter++;
            }
            if(painter == k){
                return true;
            }
        }
        return false;
            

    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int l =0;
        int r = position[n-1]-position[0];
        int ans =-1;

        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(position,m,mid)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return ans;
    }
};