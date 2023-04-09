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

bool isCompleteTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    bool facedNull = false;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *t = q.front();
            q.pop();
            if (t == nullptr) facedNull = true;
            else {
                if (facedNull) return false;
                q.push(t->left);
                q.push(t->right);
            }
        }
    }
    return true;
}

int main() {
    return 0;
}