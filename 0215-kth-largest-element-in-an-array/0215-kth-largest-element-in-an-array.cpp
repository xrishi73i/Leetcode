class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int ,vector<int>,greater<int>> pq;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<n;i++){
            pq.push(nums[i]);   //this one insert into the queue
            pq.pop();   //this one remove from the first place 
        }
        return pq.top();

    }

    //time complexity (n log k ) k because at most k elemetns 
    //space (k);

    //brute force sort and get the element space 1, complexity (nlogn);
};