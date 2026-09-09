class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        queue<tuple<TreeNode*, int, int>> q;

        q.push({root, 0, 0});

        unordered_map<int, vector<pair<int, int>>> mp;

        int start = INT_MAX;
        int end = INT_MIN;

        while (!q.empty()) {

            auto [curr, dist, level] = q.front();
            q.pop();

            // Update minimum and maximum column
            start = min(start, dist);
            end = max(end, dist);

            // Store {level, value} inside the column
            mp[dist].push_back({level, curr->val});

            // Left child → column - 1, level + 1
            if (curr->left) {
                q.push({curr->left, dist - 1, level + 1});
            }

            // Right child → column + 1, level + 1
            if (curr->right) {
                q.push({curr->right, dist + 1, level + 1});
            }
        }

        vector<vector<int>> ans;

        // Go through columns from left to right
        for (int dist = start; dist <= end; dist++) {

            // Sort by level first,
            // and if level is same, sort by value.
            sort(mp[dist].begin(), mp[dist].end());

            vector<int> line;

            // Extract only the node values
            for (auto [level, value] : mp[dist]) {   // see this thing imp
                line.push_back(value); 
            }

            ans.push_back(line);
        }

        return ans;
    }
};