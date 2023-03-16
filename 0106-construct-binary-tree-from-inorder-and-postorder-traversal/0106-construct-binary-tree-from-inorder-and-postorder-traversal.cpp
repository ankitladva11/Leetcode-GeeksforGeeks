class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size()-1;
        unordered_map<int, int> in_map;
        for(int i = 0; i < inorder.size(); i++)
        {
            int n = inorder[i];
            in_map[n] = i;
        }
        return solver(in_map, 0, len, postorder, 0, len);
    }

    TreeNode* solver(unordered_map<int, int>& inorder_map, int a, int b, vector<int>& postorder, int p, int q)
    {
        if(b<a || q<p)
        {
            return NULL;
        }
        int rootVal = postorder[q];
        TreeNode* ans = new TreeNode(rootVal);
        if(b-a == 0)
        {
            return ans;
        }
        int i = inorder_map[rootVal];
        int rLen = b-i;
        ans->right = solver(inorder_map, i+1,b, postorder, q-rLen, q-1);
        ans->left = solver(inorder_map, a,i-1, postorder, p, q-rLen-1);
        return ans;
    }
};