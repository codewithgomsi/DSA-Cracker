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
        if(!head){
            return head;
        }
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *cnext=NULL;
        while(curr){
            cnext=curr->next;
            curr->next=prev;
            prev=curr;
            curr=cnext;
        }
        head=prev;
        return head;

           }
           
};