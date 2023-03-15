class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        vector <int> v;
        queue <TreeNode*> q;
        TreeNode* p;
        q.push(root);
        while (!q.empty()) {
            p = q.front();
            q.pop();
            if (!p) {
                v.push_back(-1);
                continue;
            }
            v.push_back(p->val);
            q.push(p->left);
            q.push(p->right);
        }
        int l = 0;
        for (int x : v) {
            if (l && x != -1)
            return false;
            if (x == -1)
            l = 1;
        }
        return true;
    }
};