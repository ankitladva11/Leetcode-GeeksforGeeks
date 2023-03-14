class Solution {
public:
    vector<int>ans;
    void solve(TreeNode* root,string n)
    {

         n=n+to_string(root->val);
        if(root->left==NULL&&root->right==NULL)
        {
            ans.push_back(stoi(n));
            return;
        }
       
        if(root->left!=NULL)
        {
            solve(root->left,n);
        }
        if(root->right!=NULL)
        {
            
            solve(root->right,n);
        }
        
    }
    int sumNumbers(TreeNode* root) {
        if(root->left==NULL&&root->right==NULL)
        return root->val;
        solve(root,"");
        int res=0;
        for(auto &it:ans)
        {res+=it;
        }
        return res;
    }
};