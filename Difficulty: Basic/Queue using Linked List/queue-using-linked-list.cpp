class Node {
  public:
    int data;       // Stores the value of the node
    Node* next;     // Pointer to the next node in the queue

    Node(int new_data) {
        data = new_data;   // Initialize node with given data
        next = nullptr;    // Next pointer set to null initially
    }
};

class myQueue {
     Node *front,*rear;   // Pointers to the front and rear of the queue
     int count=0;         // Keeps track of the number of elements in the queue
  public:
    myQueue() {
        // Initialize queue as empty
        front = rear = NULL;
    }

    bool isEmpty() {
        // Queue is empty if front pointer is NULL
        return front == NULL;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        if(isEmpty()){
            // If queue is empty, create new node and set both front and rear
            rear = new Node(x);
            front = rear;
            count++;
        } else {
            // Create a new node and link it to the current rear
            Node *temp = new Node(x);
            rear->next = temp;   // Attach new node at the end
            rear = rear->next;   // Move rear pointer to new node
            count++;
    }
    }

    void dequeue() {
        // Removes the front element of the queue
        if(isEmpty()){
            return; // Nothing to remove
        } else if(front == rear){
            // Only one element present, reset queue to empty
            front = rear = NULL;
            count = 0;
        } else {
            // Remove front node and move pointer forward
            Node *temp = front;
            front = front->next;
            delete temp;   // Free memory of removed node
            count--;
        }
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(isEmpty()){
            return -1;
        }
        return front->data;
    }

    int size() {
        // Returns the current size of the queue
        return count;
    }
};
