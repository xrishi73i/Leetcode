class Solution {
public:
    int maxArea(vector<int>& height) {
        int l =0;
        int r = height.size()-1;
        int area =0;
        int maxi =0;
        
        while(l<r){
            int width = r-l ;
            area = max(width,1) * min(height[l],height[r]);
            maxi = max(area,maxi);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }


        }
        return maxi;
        
    }
};