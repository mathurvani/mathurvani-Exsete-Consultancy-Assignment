#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    class Node{
    public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int k, int v){
            key = k;
            value = v;
            next = NULL;
            prev = NULL;
        }
    };

    unordered_map<int, Node*> m;
    Node* head;
    Node* tail;
    int cap;

public:

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void inserAtFront(Node* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    int get(int key) {
        if (m.find(key) == m.end()){
            return -1;
        }
        Node* node = m[key];
        remove(node);
        inserAtFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()){
            Node* node = m[key];
            node->value = value;
            remove(node);
            inserAtFront(node);
        }
        else {
            if (m.size() == cap){
                Node* lru = tail->prev;
                remove(lru);
                m.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            inserAtFront(node);
            m[key] = node;
        }
    }
};


int main() {
    int capacity;
    cin >> capacity;     // read cache capacity

    LRUCache cache(capacity);

    string command;
    while (cin >> command) {
        if (command == "EXIT") {
            break;
        }
        else if (command == "put") {
            int key, value;
            cin >> key >> value;
            cache.put(key, value);
        }
        else if (command == "get") {
            int key;
            cin >> key;
            cout << cache.get(key) << endl;
        }
    }

    return 0;
}
