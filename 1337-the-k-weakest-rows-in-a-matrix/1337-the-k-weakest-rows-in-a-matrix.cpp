class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> >pq;

        vector<int>num;

        for(int i=0;i<mat.size();i++){
            int p = accumulate(mat[i].begin(),mat[i].end(),0);
            pq.push({p,i});
        }

        while(k--){
            num.push_back(pq.top().second);
            pq.pop();
        }
        return num;




    }
};