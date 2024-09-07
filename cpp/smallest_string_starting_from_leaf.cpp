//
// Created by Harsha Vardhan on 01/04/22.
//

#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string getLexicographicallySmallerString(string first, string second) {
    if (first.empty()) return second;
    else if (second.empty()) return first;
    else {
        int minSize = min(first.size(), second.size());
        for (int i = 0; i < minSize; i++) {
            if (first[i] < second[i]) return first;
            if (first[i] > second[i]) return second;
        }
    }
    return first;
}

void smallestFromLeafHelper(TreeNode *root, string s, string &ans) {
    char c = 'a' + root->val;
    if (root->left == nullptr && root->right == nullptr) {
        string tmp = s + c;
        reverse(tmp.begin(), tmp.end());
        ans = getLexicographicallySmallerString(tmp, ans);
    }
    if (root->left) {
        smallestFromLeafHelper(root->left, s + c, ans);
    }
    if (root->right) {
        smallestFromLeafHelper(root->right, s + c, ans);
    }
}

string smallestFromLeaf(TreeNode *root) {
    string ans = "";
    smallestFromLeafHelper(root, "", ans);
    return ans;
}

int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    cout << smallestFromLeaf(root);
    return 0;
}
