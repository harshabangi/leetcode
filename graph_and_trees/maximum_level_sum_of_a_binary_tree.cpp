//
// Created by Harsha Vardhan on 30/01/22.
//

#include <iostream>
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

int maxLevelSum(TreeNode *root) {
    if (root == nullptr) return 0;
    queue<TreeNode *> q;
    q.push(root);
    int ans = INT_MIN;
    int level = 1;
    int l = 0;
    while (!q.empty()) {
        int size = q.size();
        l++;
        int tmp = 0;
        for (int i = 0; i < size; i++) {
            TreeNode *t = q.front();
            q.pop();
            tmp += t->val;
            if (t->left != nullptr) q.push(t->left);
            if (t->right != nullptr) q.push(t->right);
        }
        if (tmp > ans) {
           ans = tmp;
           level = l;
        }
    }
    return level;
}


int main() {
    cout << maxLevelSum(nullptr) << "\n";
    return 0;
}
