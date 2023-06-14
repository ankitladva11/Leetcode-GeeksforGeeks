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
//     int getMinimumDifference(TreeNode* root) {
//         int minn=100001;
//         if(!root)return minn;
//         if(root->left!=NULL && root->right!=NULL){
//         minn=min(minn,min(abs((root->left->val)-(root->val)),abs((root->right->val)-(root->val))));
       
//         }
//          return min(minn,min(getMinimumDifference(root->left),getMinimumDifference(root->right)));
       
//     }
      void inorder(TreeNode* root, int &ans, int &prev){
        if(!root){
            return;
        }
        
        inorder(root->left, ans,prev);
        ans = min(ans, abs(prev-root->val));
        prev  = root->val;
        inorder(root->right, ans,prev);
        
        
        
    }
    int getMinimumDifference(TreeNode* root) {
        int ans =  INT_MAX;
        int prev =  INT_MAX;
        
        inorder(root,ans, prev);
        return ans;
    }
};