#include <unordered_map>

using namespace std;

class LRUCache {
private:
    // Doubly Linked List Node Definition
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    // Helper method to remove a node from the Doubly Linked List
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Helper method to insert a node right after dummy head (Most Recently Used position)
    void insertAfterHead(Node* node) {
        Node* currAfterHead = head->next;

        node->next = currAfterHead;
        node->prev = head;

        head->next = node;
        currAfterHead->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        
        // Initialize dummy head and dummy tail
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // Move to the front (Most Recently Used) by deleting and re-inserting
        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }
    
    void put(int key, int value) {
        // Case 1: Key already exists -> Update value & move node to front
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;

            deleteNode(node);
            insertAfterHead(node);
        } 
        // Case 2: Key does not exist
        else {
            // If cache reaches max capacity, evict Least Recently Used (node before tail)
            if (mp.size() == cap) {
                Node* lruNode = tail->prev;
                mp.erase(lruNode->key);
                deleteNode(lruNode);
                delete lruNode; // Free memory
            }

            // Create and insert the new node
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */