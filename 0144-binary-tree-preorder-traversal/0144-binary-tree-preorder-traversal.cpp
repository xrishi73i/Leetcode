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
        void helper(TreeNode* root,vector<int>&v){
            if(root == NULL){
                return;
            }
            //preoder root will be print first 
            v.push_back(root->val);
            //traverse the left sub tree 
            helper(root->left,v);
            helper(root->right,v);


        }
public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        helper(root,v);
        return v;
    }
};