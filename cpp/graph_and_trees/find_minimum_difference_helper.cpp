//
// Created by Harsha Vardhan on 19/06/22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getMinimumDifference(TreeNode *root) {
    stack<TreeNode *> st;
    TreeNode *curr = root;
    int ans = INT_MAX;
    int prev = -1;
    while (curr != NULL && !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        if (prev != -1) {
            ans = min(ans, abs(prev - curr->val));
        }
        prev = curr->val;
        st.pop();
        curr = curr->right;
    }
    return ans;
}

int main() {
    return 0;
}
