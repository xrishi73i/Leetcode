class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q) {
        // 1. Base case
        if (root == NULL || root == p || root == q) {
            return root;
        }

        // 2. Search both subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 3. Targets found on opposite sides
        if (left != NULL && right != NULL) {
            return root;
        }

        // 4. Pass the result upward
        if (left != NULL) {
            return left;
        }
        else {
            return right;
        }
    }
};