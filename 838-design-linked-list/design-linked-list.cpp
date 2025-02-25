class MyLinkedList {
public:
    list<int> l; // Using STL list as a doubly linked list

    MyLinkedList() {} // Constructor (no need to initialize anything)

    int get(int index) {
        if (index < 0 || index >= l.size()) return -1; // Check bounds
        return *next(l.begin(), index);
    }

    void addAtHead(int val) {
        l.push_front(val);
    }

    void addAtTail(int val) {
        l.push_back(val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > l.size()) return; // Check bounds
        auto it = l.begin();
        advance(it, index);
        l.insert(it, val);
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= l.size()) return; // Check bounds
        auto it = l.begin();
        advance(it, index);
        l.erase(it);
    }
};
