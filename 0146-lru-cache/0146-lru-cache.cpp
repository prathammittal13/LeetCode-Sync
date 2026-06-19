
class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        // Constructor to initialize node
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };
    class LRUCache {
public:
Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    // Capacity of cache
    int cap;
    // Hash map to store key-node mapping
    unordered_map<int, Node*> m;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    // Function to remove a given node from list
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* resNode = m[key];
            int res = resNode->val;
            // Remove old mapping
            m.erase(key);
            // Move accessed node to front
            deleteNode(resNode);
            addNode(resNode);
            // Update map
            m[key] = head->next;
            return res;
        }
        // If not found
        return -1;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        // If capacity reached
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        // Insert new node at front
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */