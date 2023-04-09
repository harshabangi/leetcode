//
// Created by Harsha Vardhan on 31/12/21.
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

ListNode *swapPairs(ListNode *head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    //1, 2, 3, 4, 5, 6
    ListNode *tmp = head;
    ListNode *tmp1 = head->next;
    ListNode *tmp2 = head->next->next;
    tmp1->next = tmp;
    tmp->next = swapPairs(tmp2);
    return tmp1;
}

ListNode* swapNodesInPairs(ListNode *head) {
    if (head == NULL) return head;
    if (head->next == NULL) return head;
    ListNode *tmp = head;
    stack<ListNode *> st;
    // 1->2, 3->4, 5->6
    // 2->1, 4->3, 6->5
    while (tmp && tmp->next) {
        ListNode *x = tmp->next->next;
        ListNode *first = tmp;
        ListNode *second = tmp->next;
        second->next = first;
        st.push(second);
        tmp = x;
    }
    if (tmp != NULL) st.push(tmp);
    ListNode *prev = NULL;
    ListNode *z = NULL;
    while (!st.empty()) {
        z = st.top();
        st.pop();
        if (z->next != NULL) {
            z->next->next = prev;
        } else {
            z->next = prev;
        }
        prev = z;
    }
    return prev;
}

int main() {

}
