//
// Created by Harsha Vardhan on 01/04/22.
//

#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void sumNumbersHelper(TreeNode *root, string s, int &ans) {
    if (root->left == nullptr && root->right == nullptr) {
        ans += stoi(s + to_string(root->val));
        return;
    }
    if (root->left) {
        sumNumbersHelper(root->left, s + to_string(root->val), ans);
    }
    if (root->right) {
        sumNumbersHelper(root->right, s + to_string(root->val), ans);
    }
}

int sumNumbers(TreeNode *root) {
    int ans = 0;
    sumNumbersHelper(root, "", ans);
    return ans;
}

int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    cout << sumNumbers(root);
    return 0;
}
