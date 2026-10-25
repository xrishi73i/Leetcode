class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // priority_queue<pair<int,int>, vector<int> , greater<int>>>pq;
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
                > pq;

        for(int i=0;i<arr.size();i++){
            int pp = abs(arr[i]-x);
  
            pq.push({pp,arr[i]});

        }
        vector<int>a;
        for(int i=0;i<k;i++){
            a.push_back(pq.top().second);
            pq.pop();
        }
 
        
        sort(a.begin(),a.end());
        return a;

    }
};