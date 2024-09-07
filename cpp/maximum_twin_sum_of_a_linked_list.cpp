//
// Created by Harsha Vardhan on 23/04/22.
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

void print(ListNode *t) {
    while (t != nullptr) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << "\n";
}

int pairSum(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }


    ListNode *prev = nullptr;
    ListNode *next;
    ListNode *curr = slow->next;
    slow->next = nullptr;
    // reverse

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    print(head);
    print(prev);

    int mx = INT_MIN;
    while (head != nullptr && prev != nullptr) {
        mx = max((prev->val + head->val), mx);
        prev = prev->next;
        head = head->next;
    }
    return mx;
}

int main() {
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
//    pairSum(head);
    cout << pairSum(head) << "\n";
    return 0;
}
