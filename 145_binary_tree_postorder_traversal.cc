#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

void postorderToVector(TreeNode *root, vector<int> &ret) {
    if (root == NULL) return ;
    postorderToVector(root->left, ret);
    postorderToVector(root->right, ret);
    ret.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ret;
    postorderToVector(root, ret);
    return ret;
}

int main() {
    return 0;
}
