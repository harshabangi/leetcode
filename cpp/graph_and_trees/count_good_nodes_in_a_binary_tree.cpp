//
// Created by Harsha Vardhan on 20/05/22.
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

int goodNodesHelper(TreeNode *root, int mx) {
    if (root->left == nullptr && root->right == nullptr) return 0;
    int l = 0, r = 0;
    if (root->left) {
        if (root->left->val >= mx) {
            l = 1 + goodNodesHelper(root->left, root->left->val);
        } else {
            l = goodNodesHelper(root->left, mx);
        }
    }
    if (root->right) {
        if (root->right->val >= mx) {
            r = 1 + goodNodesHelper(root->right, root->right->val);
        } else {
            r = goodNodesHelper(root->right, mx);
        }
    }
    return l + r;
}

int goodNodes(TreeNode *root) {
    return 1 + goodNodesHelper(root, root->val);
}

int main() {
    return 0;
}
