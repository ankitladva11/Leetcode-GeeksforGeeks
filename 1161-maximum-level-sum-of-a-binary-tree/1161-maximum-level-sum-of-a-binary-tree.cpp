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
    int maxLevelSum(TreeNode* root) {
        int levela=1;
        int leveli=0;
        int suma=INT_MIN;
        if(!root)return -1;
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        TreeNode* first=root;
        queue<TreeNode *> temp;
        temp.push(root);
        while(!temp.empty()){
            int size=temp.size();
            int sumi=0;
            for(int i=0;i<size;i++){
                first=temp.front();
            temp.pop();
            if(first->left!=NULL){
            temp.push(first->left);
          }
           if(first->right!=NULL){
            temp.push(first->right);
          }   sumi+=first->val;
            
            }
            leveli+=1;
            if(sumi>suma){
                suma=sumi;
                levela=leveli;
            }
        }
        return levela;
        
    }
};