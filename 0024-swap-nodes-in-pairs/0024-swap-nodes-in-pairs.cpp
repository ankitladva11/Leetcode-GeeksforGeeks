/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode*ans=head->next;
       ListNode*prev=head;
       ListNode*curr=head->next;
       ListNode*ahead=head->next->next;

       curr->next=prev;
       prev->next=ahead;


       ListNode* left=swapPairs(ahead);
       prev->next=left;
       return ans;


        
    }
};