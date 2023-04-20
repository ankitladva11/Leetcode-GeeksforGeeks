class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long maxi=1;
        while(!q.empty()){
            int sz=q.size();
            long long start=q.front().second;
            while(sz-->0){
                TreeNode* temp=q.front().first;
                long long cnt=q.front().second-start;
                maxi=max(maxi,cnt+1);
                //cout<<temp->val<<" "<<cnt<<endl;
                q.pop();
                if(temp->left!=NULL)
                    q.push({temp->left,2*cnt+1});
                if(temp->right!=NULL)
                    q.push({temp->right,2*cnt+2});
            }
        }
        return maxi;
    }
};