//
// Created by Harsha Vardhan on 27/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void invertTreeHelper(TreeNode* root) {
    if (root == nullptr) return;
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTreeHelper(root->left);
    invertTreeHelper(root->right);
}

TreeNode* invertTree(TreeNode* root) {
    invertTreeHelper(root);
    return root;
}

int main() {
    return 0;
}
