//
// Created by Harsha Vardhan on 27/06/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findLeftHeight(TreeNode* root) {
    int count = 0;
    while (root != nullptr) {
        count++;
        root = root->left;
    }
    return count;
}

int findRightHeight(TreeNode* root) {
    int count = 0;
    while (root != nullptr) {
        count++;
        root = root->right;
    }
    return count;
}

int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    int ans = 0;
    int l = findLeftHeight(root);
    int r = findRightHeight(root);
    if (l != r) {
        ans += (1 + countNodes(root->left) + countNodes(root->right));
    } else {
        ans += pow(2, l) - 1;
    }
    return ans;
}

int main() {
    return 0;
}
