class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();  // Time: O(1), Space: O(1)

        // Step 1: Build frequency map
        for (auto it : nums) {
            mp[it]++;
            // Average time per operation: O(1)
            // Total average time: O(n)
            // Map space: O(m)
        }

        // Step 2: Create max-heap
        priority_queue<pair<int, int>> pq;

        for (auto it : mp) {
            pq.push({it.second, it.first});
            // Each push: O(log m)
            // Total time: O(m log m)
            // Heap space: O(m)
            // frequency, original number
        }

        // Step 3: Extract top k frequent elements
        vector<int> v;

        for (int i = 0; i < k; i++) {
            v.push_back(pq.top().second);
            // pq.top(): O(1)
            // v.push_back(): Amortized O(1)

            pq.pop();
            // O(log m) per pop
            // Total loop time: O(k log m)
        }

        return v;  // O(1) for returning the vector by move/NRVO in typical implementations
    }
};