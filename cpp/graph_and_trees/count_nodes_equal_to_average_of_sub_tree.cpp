//
// Created by Harsha Vardhan on 20/05/22.
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

struct store {
    int sum;
    int countOfSubTrees;
    int numberOfNodes;

    store(int sum, int countOfSubTrees, int numberOfNodes) : sum(sum), countOfSubTrees(countOfSubTrees),
                                                             numberOfNodes(numberOfNodes) {}
};

store averageOfSubtreeHelper(TreeNode *root) {
    if (root->left == nullptr && root->right == nullptr) {
        return store{root->val, 1, 1};
    }
    store l = store(0, 0, 0), r = store(0, 0, 0);
    if (root->left) {
        l = averageOfSubtreeHelper(root->left);
    }
    if (root->right) {
        r = averageOfSubtreeHelper(root->right);
    }
    int k = root->val == (l.sum + r.sum + root->val) / (l.numberOfNodes + r.numberOfNodes + 1) ? l.countOfSubTrees +
                                                                                                 r.countOfSubTrees + 1 :
            l.countOfSubTrees + r.countOfSubTrees;
    return store{l.sum + r.sum + root->val, k, l.numberOfNodes + r.numberOfNodes + 1};
}

int averageOfSubtree(TreeNode *root) {
    return averageOfSubtreeHelper(root).countOfSubTrees;
}

int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    cout << averageOfSubtree(root);
    return 0;
}
