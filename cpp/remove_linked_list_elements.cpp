//
// Created by Harsha Vardhan on 19/01/22.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    if (head == NULL) return NULL;
    if (head->val != val) {
        head->next = removeElements(head->next, val);
    } else {
        return removeElements(head->next, val);
    }
    return head;
}

int main() {
    ListNode *prev = NULL;
    ListNode *z = NULL;
    int n = 7;
    for (int i = 0; i < n; i++) {
        z = new ListNode(n - i, prev);
        prev = z;
    }
    z = removeElements(z, 4);
    while (z != NULL) {
        cout << z->val;
        z = z->next;
    }
    return 0;
}