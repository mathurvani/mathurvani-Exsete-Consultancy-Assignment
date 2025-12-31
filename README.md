# EXSETE CONSULTANCY ASSIGNMENT:

# Q1.
#include <iostream>
#include <string>
using namespace std;

int countChar(const string& s, char c) {
    int count = 0; // for keeping track of number of character in the string matching  with char c
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            count++;
        }
    }
    return count;
}

int main() {
    string s;
    char c;
    getline(cin, s);  //include space in input string
    cin >> c;   // input character

    cout << countChar(s, c);
}



# Q2.
#include <iostream>
using namespace std;
// array to store 
int num[1000];

int fib(int n) {
    if (n == 1 || n == 2)
        return 1;
    if (num[n] != 0)  //base case for recursion
        return num[n];

    num[n] = fib(n - 1) + fib(n - 2);
    return num[n];
}
int main() {
    int n, m;
    cin >> n >> m;
if (n > m) {
        cout << "Invalid input! Should satisfy n<=m";
        return 0;
    }
for (int i = n; i <= m; i++) {
        cout << fib(i) << " ";
    }

    return 0;
}
# Q3.
#include <iostream>
#include <unordered_map>
using namespace std;

// Node of doubly linked list
class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> mp;

    Node* head; // dummy head
    Node* tail; // dummy tail

    // add node right after head
    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // remove node from list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        removeNode(node);
        addToFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // key already exists
            Node* node = mp[key];
            node->value = value;
            removeNode(node);
            addToFront(node);
        } else {
            // new key
            if (mp.size() == capacity) {
                // remove least recently used
                Node* lru = tail->prev;
                mp.erase(lru->key);
                removeNode(lru);
                delete lru;
            }

            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            addToFront(newNode);
        }
    }
};

int main() {
    int C;
    cin >> C;

    LRUCache cache(C);

    string command;
    while (cin >> command) {
        if (command == "EXIT")
            break;

        if (command == "put") {
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
