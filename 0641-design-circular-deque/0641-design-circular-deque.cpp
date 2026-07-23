class MyCircularDeque {
    int * arr;
    int front, rear, size;
public:
    MyCircularDeque(int k) {
        front = rear = -1;          // Initially empty
        arr = new int[k];           // Allocate array of size k
        size = k;
    }
    
    bool insertFront(int value) {
        if(isEmpty()){              // Case 1: Empty deque
            front = rear = 0;
            arr[rear] = value;
            return 1;
        } else if(isFull()){        // Case 2: Full deque
            return 0;
        } else{                     // Case 3: Normal insert at front
            front = (front - 1 + size) % size; // Circular decrement
            arr[front] = value;
            return 1;
        }
    }
    
    bool insertLast(int value) {
        if(isEmpty()){              // Case 1: Empty deque
            front = rear = 0;
            arr[rear] = value;
            return 1;
        } else if(isFull()){        // Case 2: Full deque
            return 0;
        } else{                     // Case 3: Normal insert at rear
            rear = (rear + 1 + size) % size; // Circular increment
            arr[rear] = value;
            return 1;
        } 
    }
    
    bool deleteFront() {
        if(isEmpty()){              // Case 1: Empty deque
            return 0;
        } else if(front == rear){   // Case 2: Single element
            front = rear = -1;      // Reset to empty
            return 1;
        } else{                     // Case 3: Normal delete
            front = (front + 1 + size) % size; 
            return 1;
        } 
    }
    
    bool deleteLast() {
        if(isEmpty()){              // Case 1: Empty deque
            return 0;
        } else if(front == rear){   // Case 2: Single element
            front = rear = -1;      // Reset to empty
            return 1;
        } else{                     // Case 3: Normal delete
            rear = (rear - 1 + size) % size; 
            return 1;
        } 
    }
    
    int getFront() {
        if(isEmpty()){              // Empty deque
            return -1;
        } else{
            return arr[front];      // Front element
        }
    }
    
    int getRear() {
        if(isEmpty()){              // Empty deque
            return -1;
        } else{
            return arr[rear];       // Rear element
        }
    }
    
    bool isEmpty() {
        return front == -1;         // ✅ Empty when both reset
    }
    
    bool isFull() {
        return (rear + 1) % size == front; // ✅ Full when next rear wraps to front
    }
};

/**
 * -------------------- Quick Revision Notes --------------------
 * Empty condition: front == -1
 * Full condition: (rear + 1) % size == front
 * Insert Front: circular decrement front
 * Insert Last: circular increment rear
 * Delete Front: circular increment front
 * Delete Last: circular decrement rear
 * Reset to empty: when front == rear, set both to -1
 *
 * -------------------- Dry Run Example (size = 3) --------------------
 * 1. insertLast(10) → front=0, rear=0, arr[0]=10
 * 2. insertLast(20) → rear=1, arr[1]=20
 * 3. insertFront(5) → front=2, arr[2]=5
 *    Deque = [5,10,20]
 * 4. getFront() → 5
 * 5. getRear() → 20
 * 6. deleteFront() → front=0 → deque = [10,20]
 * 7. deleteLast() → rear=0 → deque = [10]
 * 8. isEmpty() → false
 * 9. isFull() → false
 *
 * -------------------- Pattern to Learn --------------------
 * - This is the **Circular Array + Modulo pattern

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(size);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */