//
// Created by Harsha Vardhan on 24/01/22.
//

#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {};

    string string() {
        return "(" + to_string(key) + ", " + to_string(value) + ")";
    }

    void updateValue(int value) {
        this->value = value;
    }
};

Node *head = nullptr;
Node *tail = nullptr;
unordered_map<int, Node *> umap;
int size = 0;
int capacity = 2;


void print_doubly_linked_list() {
    string s;
    Node *tmp = head;
    while (tmp != nullptr) {
        s += tmp->string();
        s += "->";
        tmp = tmp->next;
    }
    cout << s << "\n";
}

void add_node_to_the_tail(Node *z) {
    if (head == nullptr && tail == nullptr) {
        head = z;
        tail = z;
    } else {
        z->prev = tail;
        z->next = nullptr;
        tail->next = z;
        tail = z;
    }
}

void refer(Node *z) {
    if (z->key == head->key) {
        if (head->next == nullptr) return;
        else {
            head = head->next;
            head->prev = nullptr;
            add_node_to_the_tail(z);
        }
    } else if (z->key == tail->key) {
        //do Nothing
    } else {
        z->prev->next = z->next;
        z->next->prev = z->prev;
        add_node_to_the_tail(z);
    }
}

int get(int key) {
    int value = -1;
    if (umap.find(key) != umap.end()) {
        Node *tmp = umap[key];
        value = tmp->value;
        refer(umap[key]);
    }
    return value;
}

void evict_least_recently_used_node() {
    if (head == tail) {
        umap.erase(head->key);
        head = nullptr;
        tail = nullptr;
    } else {
        Node *t = head;
        head = head->next;
        head->prev = nullptr;
        t->next = nullptr;
        t->prev = nullptr;
        umap.erase(t->key);
        delete (t);
    }
}

void put(int key, int value) {
    if (umap.find(key) != umap.end()) {
        Node *k = umap[key];
        k->updateValue(value);
        umap[key] = k;
        refer(k);
    } else {
        if (size == capacity) {
            evict_least_recently_used_node();
        } else {
            size++;
        }
        Node *t = new Node(key, value);
        add_node_to_the_tail(t);
        umap[key] = t;
    }
}

int main() {
    put(1, 1);
    print_doubly_linked_list();
    put(2, 2);
    print_doubly_linked_list();
    cout << get(1) << "\n";
    print_doubly_linked_list();
    put(3, 3);
    print_doubly_linked_list();
    cout << get(2) << "\n";
    put(4, 4);
    print_doubly_linked_list();
    cout << get(1) << "\n";
    print_doubly_linked_list();
    cout << get(3) << "\n";
    print_doubly_linked_list();
    cout << get(4) << "\n";
    print_doubly_linked_list();
    put(4, 5);
    print_doubly_linked_list();
    cout << get(4) << "\n";
    print_doubly_linked_list();
    cout << get(3) << "\n";
    print_doubly_linked_list();
    put(7, 8);
    print_doubly_linked_list();
    cout << get(7) << "\n";
    return 0;
}
