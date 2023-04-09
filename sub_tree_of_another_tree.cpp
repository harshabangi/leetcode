//
// Created by Harsha Vardhan on 24/04/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSubTreeHelper(TreeNode *root, TreeNode *subRoot) {
    if (root && !subRoot) return false;
    if (!root && subRoot) return false;
    if (!root && !subRoot) return true;
    return (root->val == subRoot->val) && isSubTreeHelper(root->left, subRoot->left)
           && isSubTreeHelper(root->right, subRoot->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (root == nullptr) return false;
    if (root->val == subRoot->val) {
        if (isSubTreeHelper(root, subRoot)) return true;
    }
    isSubtree(root->left, subRoot);
    isSubtree(root->right, subRoot);
    return false;
}

int main() {
    return 0;
}
