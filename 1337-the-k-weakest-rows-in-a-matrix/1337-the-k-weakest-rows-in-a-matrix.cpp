

class Solution {
public:
template<typename T>
using maxHeap = priority_queue<T>;

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat[0].size();
        int n = mat.size();

        maxHeap<pair<int,int>>pq;

        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<m;j++){
                if(mat[i][j] ==1){
                    cnt++;
                }
            }
            pq.push({cnt,i});

            if(pq.size()>k){
                pq.pop();
            }
            //here we used the size k only better then our prev solution.

        }
        vector<int>ans(k);
        for(int i=k-1;i>=0;i--){
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    
    }
};