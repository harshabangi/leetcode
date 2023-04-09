//
// Created by Harsha Vardhan on 08/03/22.
//

#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 *           2
 *          / \
 *       null  2
 *            / \
 *          null  2
 *               / \
 *             null 1
 * */


bool dfs(TreeNode *root, ListNode *tmp) {
    if (tmp == nullptr) {
        return true;
    }
    if (root == nullptr) return false;
    if (root->val != tmp->val) return false;
    return dfs(root->left, tmp->next) || dfs(root->right, tmp->next);
}

bool solve(TreeNode *root, ListNode *head) {
    if (root == nullptr) return false;
    if (root->val != head->val) return false;
    if (root->val == head->val) {
        if (dfs(root, head)) {
            return true;
        }
    }
    return solve(root->left, head) || solve(root->right, head);
}

bool isSubPath(ListNode *head, TreeNode *root) {
    return solve(root, head);
}

int main() {
    return 0;
}
