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
    void helper(vector<int>&v,vector<vector<int>>&ans,TreeNode* root , int target,int sum){
        if(root == NULL){
            return;
        }
        v.push_back(root->val);
        sum += root->val;
        if(root->left == NULL and root->right == NULL){
            if(target == sum){
                ans.push_back(v);
            }
        }

        helper(v,ans,root->right,target,sum);

        helper(v,ans,root->left,target,sum);
        v.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        vector<vector<int>>ans;
        helper(v,ans,root,targetSum,0);
        return ans;
    }
};