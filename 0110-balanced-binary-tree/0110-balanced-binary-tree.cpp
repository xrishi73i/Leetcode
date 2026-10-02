
class Solution {
public:
    int check(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = check(root->left);
        if(left == -1){
            return -1; // if child gives this -1; then return whole -1;
        }
        int right = check(root->right);
        if(right == -1){
            return -1;
        }
        if(abs(left - right)>1){ //rigth -left <= 1 for valid
            return -1;
        }
        return 1 + max(left,right); //returns the , height to the parents .
    }
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};