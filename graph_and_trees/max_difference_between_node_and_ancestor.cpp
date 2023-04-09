//
// Created by Harsha Vardhan on 10/04/22.
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

void dfs(TreeNode *root, int mn, int mx, int &ans) {
    if (root == nullptr) return;
    mn = min(mn, root->val);
    mx = max(mx, root->val);
    ans = max(max(ans, abs(root->val - mn)), max(ans, abs(root->val - mx)));
    dfs(root->left, mn, mx, ans);
    dfs(root->right, mn, mx, ans);
}

int maxAncestorDiff(TreeNode *root) {
    int ans = INT_MIN;
    int mn = root->val, mx = root->val;
    dfs(root, mn, mx, ans);
    return ans;
}

int main() {
    return 0;
}
