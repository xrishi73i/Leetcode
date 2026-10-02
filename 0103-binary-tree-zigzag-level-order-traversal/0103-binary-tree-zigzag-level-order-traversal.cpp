/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
             if(root == NULL){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>>ans;
        bool fu = true;
        while (!q.empty()) {
            int sz = q.size();
            vector<int>lvl(sz);
            for (int i = 0; i < sz; i++) {
                
                TreeNode* curr = q.front();
                q.pop();
                // if(i == sz-1){
                //     ans.push_back(curr->val);
                // }
                if(fu){
                    lvl[i] = curr->val;
                }else{
                    lvl[sz-i-1] = curr->val;
                }


                if(curr->left){
                    q.push(curr->left);
                }if(curr->right){
                    q.push(curr->right);
                }
            }
            fu = !fu;
            ans.push_back(lvl);


        }
        return ans;
    }
};