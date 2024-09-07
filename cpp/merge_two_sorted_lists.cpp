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

//ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//    if (list1 == NULL) return list2;
//    if (list2 == NULL) return list1;
//    if (list1->val <= list2->val) {
//        list1->next = mergeTwoLists(list1->next, list2);
//        return list1;
//    } else {
//        list2->next = mergeTwoLists(list2->next, list1);
//        return list2;
//    }
//}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == NULL && list2 == NULL) return NULL;
    stack<ListNode *> st;
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            st.push(list1);
            list1 = list1->next;
        } else {
            st.push(list2);
            list2 = list2->next;
        }
    }
    if (list1) st.push(list1);
    else st.push(list2);

    ListNode *prev = st.top();
    st.pop();
    while (!st.empty()) {
        ListNode* t = st.top();
        t->next = prev;
        prev = t;
        st.pop();
    }
    return prev;
}

int main() {
    return 0;
}
