class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l = newInterval[0];
        int r = newInterval[1];

        int i = 0;
        int n = intervals.size();
        vector<vector<int>>ans;
        //before interval 
        while(i<n and intervals[i][1] <  l){ //r comparing l 
              ans.push_back(intervals[i]);
              i++;
        }

        //overlapping case 
        while(i<n  and intervals[i][0] <= r){
            l = min(l,intervals[i][0]);
            r = max(r , intervals[i][1]);
            i++;
        }

        ans.push_back({l,r});
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};