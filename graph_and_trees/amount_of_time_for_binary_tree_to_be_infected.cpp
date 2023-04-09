//
// Created by Harsha Vardhan on 23/08/22.
//

#include <iostream>
#include <unordered_set>
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

void constructParentMap(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentMap, int &start, TreeNode *&s) {
    if (root->val == start) {
        s = root;
    }
    if (root->left) {
        parentMap[root->left] = root;
        constructParentMap(root->left, parentMap, start, s);
    }
    if (root->right) {
        parentMap[root->right] = root;
        constructParentMap(root->right, parentMap, start, s);
    }
}

int amountOfTime(TreeNode *root, int start) {
    TreeNode *l = root;
    unordered_map<TreeNode *, TreeNode *> parentMap;
    parentMap[root] = nullptr;
    TreeNode *s = nullptr;
    constructParentMap(l, parentMap, start, s);

    queue<TreeNode *> q;
    unordered_set<int> visited;

    q.push(s);
    visited.insert(start);

    int count = 0;

    while (!q.empty()) {
        int size = q.size();
        count++;

        for (int i = 0; i < size; i++) {
            TreeNode *front = q.front();
            q.pop();

            if (front->left && visited.find(front->left->val) == visited.end()) {
                visited.insert(front->left->val);
                q.push(front->left);
            }

            if (front->right && visited.find(front->right->val) == visited.end()) {
                visited.insert(front->right->val);
                q.push(front->right);
            }

            TreeNode *t = parentMap[front];
            if (t && visited.find(t->val) == visited.end()) {
                visited.insert(t->val);
                q.push(t);
            }
        }
    }
    return count - 1;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(2);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);

    cout << amountOfTime(root, 3) << "\n";
    return 0;
}
