//
// Created by Harsha Vardhan on 25/06/22.
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

int robHelper(TreeNode *root, unordered_map<TreeNode*, int>& umap) {
    if (root == NULL) return 0;
    if (umap.find(root) != umap.end()) return umap[root];
    int t1 = root->val;
    if (root->left != NULL) t1 += robHelper(root->left->left, umap) + robHelper(root->left->right, umap);
    if (root->right != NULL) t1 += robHelper(root->right->left, umap) + robHelper(root->right->right, umap);

    int t2 = 0;
    if (root->left != NULL) t2 += robHelper(root->left, umap);
    if (root->right != NULL) t2 += robHelper(root->right, umap);
    return umap[root] = max(t1, t2);
}

int rob(TreeNode *root) {
    unordered_map<TreeNode*, int> umap;
    return robHelper(root, umap);
}

int main() {
    return 0;
}