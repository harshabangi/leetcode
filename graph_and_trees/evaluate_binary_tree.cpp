//
// Created by Harsha Vardhan on 29/07/22.
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

bool evaluateTree(TreeNode* root) {
    if (root->left == nullptr && root->right == nullptr) return root->val;
    if (root->val == 2) {
        return evaluateTree(root->left) || evaluateTree(root->right);
    } else {
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
}

int main() {
    return 0;
}
