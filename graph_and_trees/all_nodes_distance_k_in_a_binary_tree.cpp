//
// Created by Harsha Vardhan on 02/04/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void fill_parent_map(TreeNode *root, TreeNode *parent, unordered_map<TreeNode *, TreeNode *> &umap) {
    if (root == nullptr) return;
    umap[root] = parent;
    fill_parent_map(root->left, root, umap);
    fill_parent_map(root->right, root, umap);
}

void dfs(TreeNode *currNode, unordered_set<TreeNode *> uset, unordered_map<TreeNode *, TreeNode *> umap,
         vector<int> &ans, int k) {
    if (currNode == nullptr || uset.find(currNode) != uset.end() || k < 0) return;
    if (k == 0) {
        ans.push_back(currNode->val);
        return;
    }
    uset.insert(currNode);
    dfs(currNode->left, uset, umap, ans, k - 1);
    dfs(currNode->right, uset, umap, ans, k - 1);
    dfs(umap[currNode], uset, umap, ans, k - 1);
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    unordered_map<TreeNode *, TreeNode *> umap;
    fill_parent_map(root, nullptr, umap);
    vector<int> ans;
    unordered_set<TreeNode *> uset;
    dfs(target, uset, umap, ans, k);
    return ans;
}

int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    cout << sumNumbers(root);
    return 0;
}
