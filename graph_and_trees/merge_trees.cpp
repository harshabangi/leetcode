//
// Created by Harsha Vardhan on 04/03/22.
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

TreeNode *mergeTreesHelper(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr) return nullptr;
    if (root1 != nullptr && root2 == nullptr) {
        return root1;
    }
    if (root1 == nullptr && root2 != nullptr) {
        return root2;
    }
    root1->val += root2->val;
    if (root1->left == nullptr) {
        root1->left = mergeTreesHelper(root1->left, root2->left);
    } else {
        mergeTreesHelper(root1->left, root2->left);
    }
    if (root1->right == nullptr) {
        root1->right = mergeTreesHelper(root1->right, root2->right);
    } else {
        mergeTreesHelper(root1->right, root2->right);
    }
    return nullptr;
}

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    TreeNode *ans = root1;
    mergeTreesHelper(root1, root2);
    return ans;
}

int main() {
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    mergeTrees(root1, root2);
    return 0;
}
