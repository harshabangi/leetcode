//
// Created by Harsha Vardhan on 14/01/22.
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

ListNode* reverseK(ListNode* head, int k, int j) {
    if (j == 0) return head;
    ListNode* next = NULL;
    ListNode* curr = head;
    ListNode* prev = NULL;
    int i = 0;
    while (i < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }
    j--;
    head->next = reverseK(curr, k, j);
    return prev;
}
int main() {
    ListNode *z = NULL;
    ListNode *prev = NULL;
    int n = 9;
    for (int i = 0; i < n; i++) {
        z = new ListNode(n - i, prev);
        prev = z;
    }
    int k = 3;
    reverseK(z, k, n/k);
    return 0;
}