#include <unordered_map>
using namespace std;
struct Node{
    int key, value;
    Node* next;
    Node* prev;
    Node(): key(-1), value(0), next(nullptr), prev(nullptr) {}
    Node(int _key, int _value): key(_key), value(_value), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    public:
        LRUCache(int capacity) {
            head = new Node();
            tail = new Node();
            head->next = tail;
            tail->prev = head;
            size = 0;
            max_capacity = capacity;
        }
        
        int get(int key) {
            if(!cache.count(key))
                return -1;
            Node *target = cache[key];
            // move to first
            // remove the node
            target->prev->next = target->next;
            target->next->prev = target->prev;
            // insert into first
            target->next = head->next;
            head->next->prev = target;
            head->next = target;
            target->prev = head;
            return target->value;

        }
        
        void put(int key, int value) {
            if(!cache.count(key)) {
                Node *new_node = new Node(key, value);
                cache[key] = new_node;
                new_node->next = head->next;
                head->next->prev = new_node;
                head->next = new_node;
                new_node->prev = head;
                ++size;
                if (size > max_capacity) {
                    Node *prev_node = tail->prev;
                    prev_node->prev->next = tail;
                    tail->prev = prev_node->prev;
                    cache.erase(prev_node->key);
                    delete prev_node;
                    --size;
                }
            } else{
                Node *curr_node = cache[key];
                curr_node->value = value;
                // 先将节点从原位置移除
                curr_node->prev->next = curr_node->next;
                curr_node->next->prev = curr_node->prev;
                // 再插入到头部
                curr_node->next = head->next;
                head->next->prev = curr_node;
                head->next = curr_node;
                curr_node->prev = head;
            }
        }
    private:
        unordered_map<int, Node*> cache;
        Node *head;
        Node *tail;
        int size;
        int max_capacity;
};
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */
