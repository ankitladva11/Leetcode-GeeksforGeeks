class Solution {
private:
    int ans = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int temp = helper(root);
        return ans;
    }
    int helper(TreeNode* root){
        if(!root) return 0;

        int left = helper(root->left);
        int right = helper(root->right);

        if(ans < left + right) ans = left + right;
        return 1 + max(left, right);
    }
};