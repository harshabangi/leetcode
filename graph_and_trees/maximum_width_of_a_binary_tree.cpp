//
// Created by Harsha Vardhan on 28/07/22.
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

int widthOfBinaryTree(TreeNode *root) {
    queue<pair<TreeNode *, int>> q;
    int ans = 0;
    q.push({root, 1});

    while (!q.empty()) {
        int size = q.size();
        int f, l;
        for (int i = 0; i < size; i++) {
            pair<TreeNode *, int> front = q.front();
            q.pop();
            if (i == 0) f = front.second;
            if (i == size - 1) l = front.second;
            if (front.first->left) {
                q.push({front.first->left, (front.second << 1) - 1});
            }
            if (front.first->right) {
                q.push({front.first->right, (front.second << 1)});
            }
        }
        ans = max(ans, l - f + 1);
    }
    return ans;
}

int main() {
    return 0;
}
