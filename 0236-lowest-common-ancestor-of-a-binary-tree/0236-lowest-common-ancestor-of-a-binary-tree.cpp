/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root, vector<TreeNode*>&path,TreeNode* target){
        if(root == NULL){
            return false;
        }
        path.push_back(root);
        if(root == target){
            return true;
        }
        
        if(check(root->left,path,target)){
            return true;
        }
        if(check(root->right,path,target)){
            return true;
        }
        path.pop_back();
        return false;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        check(root,path1,p);
        check(root,path2,q);
        int i=0;
        while(i<path1.size() and i<path2.size()  and path1[i] == path2[i]){
            i++;
        }
        return path1[i-1];


    }
};