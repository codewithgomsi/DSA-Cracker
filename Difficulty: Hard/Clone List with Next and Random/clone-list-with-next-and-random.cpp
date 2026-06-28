/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
  Node* find(Node*head,Node*head1,Node*tail_copy,Node*tail){
      if(tail->random==NULL){
          return NULL;
      }
      while(head!=tail->random){
          head=head->next;
          head1=head1->next;
      }
      return head1;
  }
    Node* cloneLinkedList(Node* head) {
        // code here
        // creating ll with only next pointer first
        // dummy node is better but I wanted to try
        Node* curr=head;
        Node * head1=NULL;
        Node*temp;
        while(curr){
           if(head1==NULL){
               head1=new Node(curr->data);
               temp=head1;
               curr=curr->next;
           }else{
               temp->next=new Node(curr->data);
               temp=temp->next;
               curr=curr->next;
           } 
        }
        // connecting random pointer
        Node *tail_copy=head1;
        Node* tail=head;
        while(tail){  // causing O(n^2) tc - n from while n from each time calling find as loop exist there too
            tail_copy->random=find(head,head1,tail_copy,tail);
            tail_copy=tail_copy->next;
            tail=tail->next;
        }
        return head1;
    }
};