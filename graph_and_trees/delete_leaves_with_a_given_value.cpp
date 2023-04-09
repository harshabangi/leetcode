//
// Created by Harsha Vardhan on 03/04/22.
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

bool isLeaf(TreeNode *node) {
    return node->left == nullptr && node->right == nullptr;
}

void pruneTree(TreeNode *current, unordered_map<TreeNode *, pair<TreeNode *, bool>> parentMap, int target) {
    if (isLeaf(current) && current->val == target) {
        pair<TreeNode *, bool> tmp = parentMap[current];
        if (tmp.first == nullptr) {
            return;
        }
        if (tmp.second) tmp.first->right = nullptr;
        else tmp.first->left = nullptr;
        pruneTree(tmp.first, parentMap, target);
    }
}

void removeLeafNodesHelper(TreeNode *current, unordered_map<TreeNode *, pair<TreeNode *, bool>> parentMap, int target) {
    pruneTree(current, parentMap, target);
    if (current->left) {
        parentMap[current->left] = make_pair(current, 0);
        removeLeafNodesHelper(current->left, parentMap, target);
    }
    if (current->right) {
        parentMap[current->right] = make_pair(current, 1);
        removeLeafNodesHelper(current->right, parentMap, target);
    }
}

TreeNode *removeLeafNodes(TreeNode *root, int target) {
    unordered_map<TreeNode *, pair<TreeNode *, bool>> parentMap;
    parentMap[root] = make_pair(nullptr, 0);
    removeLeafNodesHelper(root, parentMap, target);
    if (isLeaf(root) && root->val == target) { return nullptr; }
    else return root;
}

TreeNode *removeLeafNodes(TreeNode *root, int target) {
    if (root == nullptr) return nullptr;
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if (root->left == nullptr && root->right == nullptr && root->val == target) {
        root = nullptr;
    }
}

int main() {
    int target;
    removeLeafNodes(nullptr, target);
    return 0;
}
