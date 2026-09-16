class Solution {
public:

    vector<TreeNode*> v;

    void preorder(TreeNode* root) {

        if (root == NULL)
            return;

        v.push_back(root);

        preorder(root->left);
        preorder(root->right);
    }

    void flatten(TreeNode* root) {

        v.clear();

        preorder(root);

        for (int i = 0; i + 1 < v.size(); i++) {

            v[i]->left = NULL;
            v[i]->right = v[i + 1];
        }

        // if (v.size() > 0) {
        //     v[v.size() - 1]->left = NULL;
        //     v[v.size() - 1]->right = NULL;
        // }
    }
};