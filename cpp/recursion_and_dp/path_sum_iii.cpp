//
// Created by Harsha Vardhan on 14/04/22.
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

int 
int pathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return ;
    pathSum(root->left, targetSum);
    pathSum(root->right, targetSum);
}

int main() {
    TreeNode* root;
    pathSum(root, 8);
    return 0;
}


