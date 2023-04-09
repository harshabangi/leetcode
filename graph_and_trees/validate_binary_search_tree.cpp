//
// Created by Harsha Vardhan on 18/06/22.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isValidBSTHelper(TreeNode *curr, TreeNode *left, TreeNode *right) {
    if (curr == nullptr) return true;
    if (left != nullptr && curr->val < left->val) return false;
    if (right != nullptr && curr->val > right->val) return false;
    return isValidBSTHelper(curr->left, left, curr) && isValidBSTHelper(curr->right, curr, right);
}

bool isValidBST(TreeNode *root) {
    return isValidBSTHelper(root, nullptr, nullptr);
}

// To use directly the long values

bool isValidBSTHelper1(TreeNode *curr, long left, long right) {
    if (curr == nullptr) return true;
    if (!(curr->val > left && curr->val < right)) return false;
    return isValidBSTHelper1(curr->left, left, curr->val) && isValidBSTHelper1(curr->right, curr->val, right);
}

bool isValidBST1(TreeNode *root) {
    return isValidBSTHelper1(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    return 0;
}
