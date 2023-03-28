/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
          // your code here
        ListNode * temp=head;
        if(temp==NULL){
            return 0;
        }
        map <ListNode *,bool> visited;
        while(temp!=NULL){
            if(visited[temp]==true){
            return 1;
            }
            visited[temp]=1;
            temp=temp->next;
        }
        return 0;
    }
};