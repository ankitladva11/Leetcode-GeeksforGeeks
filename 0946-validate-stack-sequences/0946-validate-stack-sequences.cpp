class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n=pushed.size();
        int j=0;

        for(int i=0;i<n;i++)
        {   
            s.push(pushed[i]);
            if(pushed[i]==popped[j])
            {
                s.pop();
                j++;
            }

            while(!s.empty() && s.top()==popped[j])
            {
                s.pop();
                j++;
            }
        }

        if(j==n)
            return true;
        
        return false;
    }
};