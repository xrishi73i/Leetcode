class Solution {
public:
    bool helper(TreeNode* root, int targetSum, int sum) {
        if (root == NULL) {
            return false;
        }

        sum += root->val;

        if (root->left == NULL && root->right == NULL) {
            return sum == targetSum;
        }

        return helper(root->left, targetSum, sum) ||
               helper(root->right, targetSum, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum, 0);
    }
};