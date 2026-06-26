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
ListNode * reverse(ListNode * curr,ListNode* prev){
      if(curr==NULL){  // base condition
          return prev; // to return head
      }
      ListNode * fut= curr->next;
      curr->next=prev;
      return reverse(fut,curr);}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode *head1_rev=l1;
        ListNode *head2_rev=l2;
        int carry=0;
        ListNode * curr1=head1_rev;
       ListNode * curr2=head2_rev;
        ListNode * head_ans=new ListNode(0);
        ListNode * temp=head_ans;
        while(curr1&&curr2){
           int sum=(curr1->val+curr2->val+carry)%10;
           temp->next=new ListNode(sum);
           temp=temp->next;
            carry=(curr1->val+curr2->val+carry)/10;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        while(curr1){
            int sum=(curr1->val+carry)%10;
           temp->next=new ListNode(sum);
           temp=temp->next;
            carry=(curr1->val+carry)/10;
            curr1=curr1->next;
        }  
        while(curr2){
            int sum=(curr2->val+carry)%10;
           temp->next=new ListNode(sum);
           temp=temp->next;
            carry=(curr2->val+carry)/10;
            curr2=curr2->next;
        }
        while(carry){
             temp->next=new ListNode(carry);
           temp=temp->next;
           carry/=10;
        }
        // now reversing the answer ll for final ans
        ListNode *head_fans=head_ans->next;
        delete head_ans;
        return head_fans;
    }
};