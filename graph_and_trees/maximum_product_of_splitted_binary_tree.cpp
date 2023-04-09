//
// Created by Harsha Vardhan on 28/07/22.
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

long long sumOfNodes(TreeNode *root, unordered_map<TreeNode *, long long> &umap) {
    if (root == nullptr) return 0;
    return umap[root] = root->val + sumOfNodes(root->left, umap) + sumOfNodes(root->right, umap);
}

void maxProductHelper(TreeNode *root, long long &totalSum, unordered_map<TreeNode *, long long> &umap, long long &ans) {
    if (root->left == nullptr && root->right == nullptr) {
        return;
    }
    if (root->left) {
        long long l = umap[root->left];
        ans = max(ans, l * (totalSum - l));
        maxProductHelper(root->left, totalSum, umap, ans);
    }
    if (root->right) {
        long long r = umap[root->right];
        ans = max(ans, r * (totalSum - r));
        maxProductHelper(root->right, totalSum, umap, ans);
    }
}

long long maxProductHelper1(TreeNode* root, long long& totalSum, unordered_map<TreeNode *, long long> &umap) {
    if (root->left == nullptr && root->right == nullptr) {
        return LONG_LONG_MIN;
    }
    long long ans = LONG_LONG_MIN;
    if (root->left) {
        long long l = umap[root->left];
        ans = max(ans, l * (totalSum - l));
        ans = max(ans, maxProductHelper1(root->left, totalSum, umap));
    }
    if (root->right) {
        long long r = umap[root->right];
        ans = max(ans, r * (totalSum - r));
        ans = max(ans, maxProductHelper1(root->right, totalSum, umap));
    }
    return ans;
}

int maxProduct(TreeNode *root) {
    unordered_map<TreeNode *, long long> umap;
    long long totalSum = sumOfNodes(root, umap);
//    long long ans = 0;
    long long ans = maxProductHelper1(root, totalSum, umap);
    return ans % (1000000007);
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << maxProduct(root) << "\n";
    return 0;
}