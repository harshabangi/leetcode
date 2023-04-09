//
// Created by Harsha Vardhan on 14/04/22.
//


#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isLeaf(TreeNode *node) {
    return node->left == nullptr && node->right == nullptr;
}

TreeNode *pruneTree(TreeNode *root) {
    if (root->left) {
        root->left = pruneTree(root->left);
    }
    if (root->right) {
        root->right = pruneTree(root->right);
    }
    if (isLeaf(root) && root->val == 0) return nullptr;
    return root;
}

void getMinimumDifferenceHelper(TreeNode *root, int prev, int &ans) {
    if (root->left) {
        getMinimumDifferenceHelper(root->left, prev, ans);
    }
    if (prev == -1) {
        prev = root->val;
    } else {
        ans = min(ans, abs(root->val - prev));
        prev = root->val;
    }
    if (root->right) {
        getMinimumDifferenceHelper(root->right, prev, ans);
    }
}

int main() {
    TreeNode *root;
    pruneTree(root);
    return 0;
}

