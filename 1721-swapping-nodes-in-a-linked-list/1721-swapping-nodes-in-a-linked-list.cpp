class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * t = head;
        int h=1;
        while(t)
        {
            t=t->next;
            h++;
        }
        int s=h;
        int j=0,q=0;
        t=head;
        h=1;
        
        while(t)
        {
            if(h==k)
            {
                j=t->val;
            }
            if(h==s-k)
            {
                q=t->val;
            }
            t=t->next;
            h++;
        }
        t=head;
        h=1;
        while(t)
        {
            if(h==k)
            {
                t->val=q;
            }
            if(h==s-k)
            {
                t->val=j;
            }
            t=t->next;
            h++;
        }
        
        return head;
    }
};