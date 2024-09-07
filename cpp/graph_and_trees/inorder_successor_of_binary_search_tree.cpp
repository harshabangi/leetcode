//
// Created by Harsha Vardhan on 09/06/22.
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

TreeNode *search(TreeNode *root, int p, unordered_map<TreeNode *, TreeNode *> &parentMap) {
    parentMap[root] = nullptr;
    while (true) {
        if (root->val == p) {
            break;
        }
        if (root->val > p) {
            parentMap[root->left] = root;
            root = root->left;
        } else {
            parentMap[root->right] = root;
            root = root->right;
        }
    }
    return root;
}

TreeNode *inorderSuccessor(TreeNode *root, int p) {
    unordered_map<TreeNode *, TreeNode *> parentMap;
    TreeNode *actualNode = search(root, p, parentMap);
    if (actualNode->right != nullptr) {
        actualNode = actualNode->right;
        while (actualNode->left != nullptr) {
            actualNode = actualNode->left;
        }
        return actualNode;
    } else {
        while (parentMap[actualNode] != nullptr) {
            if (parentMap[actualNode]->val > actualNode->val) {
                return parentMap[actualNode];
            } else {
                actualNode = parentMap[actualNode];
            }
        }
    }
    return nullptr;
}

int main() {
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);
    cout << inorderSuccessor(root, 10)->val << "\n";
    return 0;
}
