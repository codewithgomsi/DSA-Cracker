/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
  Node * reverse(Node * curr,Node* prev){
      if(curr==NULL){  // base condition
          return prev; // to return head
      }
      Node * fut= curr->next;
      curr->next=prev;
      return reverse(fut,curr);
      
  }
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        Node *head1_rev=reverse(head1,NULL);
        Node *head2_rev=reverse(head2,NULL);
        int carry=0;
        Node * curr1=head1_rev;
        Node * curr2=head2_rev;
        Node * head_ans=new Node(0);
        Node * temp=head_ans;
        while(curr1&&curr2){
           int sum=(curr1->data+curr2->data+carry)%10;
           temp->next=new Node(sum);
           temp=temp->next;
            carry=(curr1->data+curr2->data+carry)/10;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        while(curr1){
            int sum=(curr1->data+carry)%10;
           temp->next=new Node(sum);
           temp=temp->next;
            carry=(curr1->data+carry)/10;
            curr1=curr1->next;
        }  
        while(curr2){
            int sum=(curr2->data+carry)%10;
           temp->next=new Node(sum);
           temp=temp->next;
            carry=(curr2->data+carry)/10;
            curr2=curr2->next;
        }
        while(carry){
             temp->next=new Node(carry);
           temp=temp->next;
           carry/=10;
        }
        // now reversing the answer ll for final ans
        Node *head_fans=reverse(head_ans->next,NULL);
        // handling leading zeores
        while(head_fans->data==0){
            head_fans=head_fans->next;
        }
        return head_fans;
    }
};