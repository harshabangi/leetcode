//
// Created by Harsha Vardhan on 20/07/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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

int bfs(TreeNode *curr, unordered_map<TreeNode *, TreeNode *> &umap, int distance) {
    unordered_set<TreeNode *> uset;

    uset.insert(curr);
    queue<TreeNode *> q;
    q.push(curr);

    int level = -1;
    int ans = 0;

    while (!q.empty()) {
        int size = q.size();
        level++;
        for (int i = 0; i < size; i++) {
            TreeNode *front = q.front();
            q.pop();

            if (level > 0 && level <= distance && (front->left == nullptr && front->right == nullptr)) {
                ans++;
            }
            if (level > distance) continue;
            if (front->left && (uset.find(front->left) == uset.end())) {
                uset.insert(front->left);
                q.push(front->left);
            }
            if (front->right && (uset.find(front->right) == uset.end())) {
                uset.insert(front->right);
                q.push(front->right);
            }
            if (umap[front] && (uset.find(umap[front]) == uset.end())) {
                uset.insert(umap[front]);
                q.push(umap[front]);
            }
        }
    }
    return ans;
}

void constructParentMap(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &umap, vector<TreeNode *> &leaves) {
    if (root->left == nullptr && root->right == nullptr) {
        leaves.push_back(root);
        return;
    }
    if (root->left) {
        umap[root->left] = root;
        constructParentMap(root->left, umap, leaves);
    }
    if (root->right) {
        umap[root->right] = root;
        constructParentMap(root->right, umap, leaves);
    }
}

int countPairs(TreeNode *root, int distance) {
    unordered_map<TreeNode *, TreeNode *> umap;
    vector<TreeNode *> leaves;
    umap[root] = nullptr;
    TreeNode *t = root;
    constructParentMap(t, umap, leaves);
    int ans = 0;
    for (int i = 0; i < leaves.size(); i++) {
        ans += bfs(leaves[i], umap, distance);
    }
    return ans / 2;
}

int main() {
    TreeNode *root = new TreeNode(15);
    root->left = new TreeNode(66);
    root->right = new TreeNode(55);
    root->left->left = new TreeNode(97);
    root->left->right = new TreeNode(60);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(56);
    root->left->left->right = new TreeNode(54);
    root->right->left->right = new TreeNode(9);
    root->left->right->right = new TreeNode(49);
    root->left->right->right->right = new TreeNode(90);

    cout << countPairs(root, 5) << "\n";
    return 0;
}
