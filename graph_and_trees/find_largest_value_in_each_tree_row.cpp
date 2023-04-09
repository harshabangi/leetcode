//
// Created by Harsha Vardhan on 21/05/22.
//

#include <iostream>
#include <vector>
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


vector<int> largestValues(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr) return ans;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        int mx = INT_MIN;
        for (int i = 0; i < size; i++) {
            TreeNode *t = q.front();
            q.pop();
            mx = max(mx, t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        ans.push_back(mx);
    }
    return ans;
}

int main() {
    return 0;
}