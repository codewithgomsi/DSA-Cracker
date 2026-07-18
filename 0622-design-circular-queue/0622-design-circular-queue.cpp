class MyCircularQueue {
    int *arr;      // Array to store queue elements
    int front,rear; // Pointers to front and rear indices
    int size;      // Maximum size of the queue
public:
    MyCircularQueue(int k) {
        arr=new int[k];     // Allocate memory for k elements
        rear=front=-1;      // Initialize queue as empty
        size=k;
    }
    
    bool enQueue(int value) {
        // Insert element at rear
        if(isEmpty()){
            // First insertion: set both front and rear to 0
            rear=front=0;
            arr[rear]=value;
            return 1;
        }else if(isFull()){
            // Cannot insert if queue is full
            return 0;
        } else{
            // Move rear forward in circular manner
            rear=(rear+1)%size;
            arr[rear]=value;
            return 1;
        }
    }
    
    bool deQueue() {
        // Remove element from front
        if(isEmpty()){
            return 0; // Nothing to remove
        }
        // Only one element present
        else if(front==rear){
            front=rear=-1; // Reset queue to empty
            return 1;
        } else{
            // Move front forward in circular manner
            front=(front+1)%size;
            return 1;
        }
    }
    
    int Front() {
        // Return front element if not empty
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        // Return rear element if not empty
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        // Queue is empty if front == -1
        return front==-1;
    }
    
    bool isFull() {
        // Queue is full if next rear position equals front
        return (rear+1)%size==front;
    }
};

/**
 * Usage Example:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);   // Insert element
 * bool param_2 = obj->deQueue();        // Remove element
 * int param_3 = obj->Front();           // Get front element
 * int param_4 = obj->Rear();            // Get rear element
 * bool param_5 = obj->isEmpty();        // Check if empty
 * bool param_6 = obj->isFull();         // Check if full
 */
