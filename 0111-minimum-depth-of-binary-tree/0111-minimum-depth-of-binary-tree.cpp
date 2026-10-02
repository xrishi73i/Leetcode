
class Solution {
public:
int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL and root->right == NULL){
        return 1;
    }
    if(root->left == NULL){
        return 1 + height(root->right);
    }
    if(root->right == NULL){
        return 1+ height(root->left);
    }
 

     return 1+ min(height(root->left),height(root->right));

}
    int minDepth(TreeNode* root) {
        return height(root);
    }
};