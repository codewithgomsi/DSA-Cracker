/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node * first=new Node(0);
        first->next=head;
        head=first;
        Node * prev,*curr,*second,*front;
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
            } // linking part
            first->next=prev;
            second->next=curr;
            first=second;
        }
        first=head;
        head=head->next;
        delete first;
        return head;
    }
};