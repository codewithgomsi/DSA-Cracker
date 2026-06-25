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
ListNode *detectCycle(ListNode *head) {
        // try optimal for understanding fast and slow in depth
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        if(fast==NULL||fast->next==NULL){
            return NULL;
        }
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
 /*   brute force approach
    ListNode *detectCycle(ListNode *head) {
        // try optimal for understanding fast and slow in depth
        unordered_map <ListNode* ,bool> visited;
        ListNode *curr=head;
        while(curr){
            if(visited[curr]==1){
                break;
            }
            visited[curr]=1;
            curr=curr->next;
        }
        if(curr==NULL){ return NULL;}
        return curr;
    } */
};