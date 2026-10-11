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
 
int helper(TreeNode* root , int target,long long  sum){
        if(root == NULL){
            return 0;
        }
        int count =0;
        sum += root->val;
        
            if(target == sum){
                count ++;
            }
        

        count += helper(root->right,target,sum);

        count += helper(root->left,target,sum);
        

        return count;
}
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        vector<vector<int>>ans;
        if(root == NULL){
            return 0;
        }
        int count = helper(root,targetSum,0);
        count += pathSum(root->left,targetSum);
        count += pathSum(root->right,targetSum);

        return count;
        


    }
};