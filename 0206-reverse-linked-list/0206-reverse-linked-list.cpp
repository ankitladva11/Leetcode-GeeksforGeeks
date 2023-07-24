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
    ListNode* reverseList(ListNode* head) {
        if(!head){return head;}
        if(head->next==NULL){return head;}
        ListNode * temp1=NULL;
        ListNode * temp2=head;
        ListNode * temp3;
        while(temp2!=NULL){
           temp3=temp2->next;
            temp2->next=temp1;
            temp1=temp2;
            temp2=temp3;
        }
    return temp1;
        
    }
};