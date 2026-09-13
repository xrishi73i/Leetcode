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
    int  Max(TreeNode* root){
        while(root->right !=NULL){
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        //left node
        if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        //right node
        else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }
        //multiple case
        else{
            //root No child 
        if(root->left == NULL and root->right == NULL){
            return NULL;
        }
        //left 1 child
        if(root->left !=NULL and root->right ==NULL){
            return root->left;
        }
        // root 1 rigth child
         if(root->right !=NULL and root->left ==NULL){
            return root->right;
        }  
        //max of left child 
        int mx = Max(root->left);
        root->val = mx;

        root->left = deleteNode(root->left,mx);

        
        }
return root;
    }
};