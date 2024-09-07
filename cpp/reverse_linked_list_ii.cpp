//
// Created by Harsha Vardhan on 16/01/22.
//

#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *tmp = head;
    ListNode *prev = nullptr;
    ListNode *tail = nullptr;
    ListNode *curr = head;

    int i = 1;
    while (tmp != nullptr) {
        if (i == left - 1) prev = tmp;
        if (i == right + 1) tail = tmp;
        if (i == left) curr = tmp;
        i++;
        tmp = tmp->next;
    }
    stack<ListNode *> st;
    i = 0;
    while (i < right - left + 1) {
        st.push(curr);
        curr = curr->next;
        i++;
    }
    ListNode *x = prev;
    ListNode *top;
    while (!st.empty()) {
        top = st.top();
        if (x != nullptr) {
            x->next = top;
        } else {
            head = top;
        }
        x = top;
        st.pop();
    }
    top->next = tail;
    return head;
}

int main() {
    ListNode *curr = nullptr;
    ListNode* head = nullptr;
    int n = 2;
    for (int i = 1; i <= n; i++) {
        if (curr == nullptr) {
            curr = new ListNode(i);
            head = curr;
        }
        else {
            curr->next = new ListNode(i);
            curr = curr->next;
        }
    }
    ListNode* res = reverseBetween(head, 1, 2);
    return 0;
}
