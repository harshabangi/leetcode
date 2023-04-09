//
// Created by Harsha Vardhan on 03/02/22.
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

void binaryTreePathsHelper(TreeNode *root, vector<string> &ans, string s) {
    if (root->left == nullptr && root->right == nullptr) {
        ans.push_back(s);
        return;
    }
    if (root->left != nullptr) binaryTreePathsHelper(root->left, ans, s + "->" + to_string(root->left->val));
    if (root->right != nullptr) binaryTreePathsHelper(root->right, ans, s + "->" + to_string(root->right->val));
}


vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ans;
    string s;
    if (root == nullptr) return ans;
    else {
        binaryTreePathsHelper(root, ans, to_string(root->val));
    }
    return ans;
}

int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *level1L = new TreeNode(2);
    TreeNode *level1R = new TreeNode(3);
    TreeNode *level2R = new TreeNode(5);

    root->left = level1L;
    root->right = level1R;
    level1L->right = level2R;
    vector<string> ans = binaryTreePaths(root);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
