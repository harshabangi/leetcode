#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
 *    3
 *   1 2
 * */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *recoverTreeHelper(TreeNode *root, int prev) {
    if (root->left == nullptr || root->right == NULL) return NULL;
    TreeNode* a = recoverTreeHelper(root->left, root->val); // (2), 1
    if (a != nullptr) return a;
    if (root->val > prev) return root;
    return recoverTreeHelper(root->right, root->val);
}

// (3, INT_MIN)
// (1, 3)

void recoverTree(TreeNode *root) {

}


int main() {
    return 0;
}