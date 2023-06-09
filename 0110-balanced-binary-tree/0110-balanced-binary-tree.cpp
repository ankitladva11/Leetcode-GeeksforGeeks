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
    int height(TreeNode * node){
        // code here 
        if(node==NULL){
            return 0;
        }
        if(node->left==NULL && node->right==NULL){
            return 1;
        }
        return 1+max(height(node->left),height(node->right));
    }
    
    bool isBalanced(TreeNode* root) {
         if(!root)return 1;
        bool lb=true,rb=true;
        int lh=height(root->left);
        int rh=height(root->right);
        if(abs(lh-rh)>=2){
            return false;
        }
        else{
             lb=isBalanced(root->left);
             rb=isBalanced(root->right);
        }
        return (lb && rb);
    }
};