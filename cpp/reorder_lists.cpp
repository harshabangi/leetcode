//
// Created by Harsha Vardhan on 17/01/22.
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

void reorderList(ListNode *head) {
    stack<ListNode *> st;
    ListNode *tmp = head;
    int n = 0;
    while (tmp != NULL) {
        n++;
        st.push(tmp);
        tmp = tmp->next;
    }
    tmp = head;
    for (int i = 0; i < n / 2; i++) {
        ListNode *next = tmp->next;
        tmp->next = st.top();
        st.pop();
        tmp = tmp->next;
        tmp->next = next;
        tmp = tmp->next;
    }
    tmp->next = NULL;
}

int main() {
    ListNode *prev = NULL;
    ListNode *z = NULL;
    int n = 4;
    for (int i = 0; i < n; i++) {
        z = new ListNode(n - i, prev);
        prev = z;
    }
    reorderList(z);
    while (z != NULL) {
        cout << z->val;
        z = z->next;
    }

    return 0;
}
