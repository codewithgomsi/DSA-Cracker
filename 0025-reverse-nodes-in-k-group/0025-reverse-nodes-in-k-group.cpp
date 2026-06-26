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
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode * first=new ListNode(0);
        first->next=head;
        head=first;
        ListNode * prev,*curr,*second,*front;
        // count total no of nodes
        ListNode*temp=head;
        int count=0;
        while(temp){
        count++;
        temp=temp->next;
        } 
        // count -1 for removing dummy node count
        count--;
        while(first->next){
            prev=first;
            curr=first->next;
            second=first->next;
            int a =k;
            while(a--&&curr){
                front=curr->next;
                curr->next=prev;
                prev=curr;
                curr=front;
                count--;
            } // linking part
            first->next=prev;
            second->next=curr;
            first=second;
            if(count<k)
            break;
             }
        first=head;
        head=head->next;
        delete first;
        return head; 
    }
};