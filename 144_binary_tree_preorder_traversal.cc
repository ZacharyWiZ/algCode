#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = 0) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    //morrir's algorithm
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> record;
        preorderToVector(root, record);
        return record;
    }

private:
    void preorderToVector(TreeNode *root, vector<int> &traversalRecord) {
        TreeNode *visit = root, *precursor = NULL;
        while (visit != NULL) {
            precursor = find_precursor(visit);
            if (precursor == NULL) {
                traversalRecord.push_back(visit->val);
                visit = visit->right;
            }else if (precursor->right == NULL) {
                traversalRecord.push_back(visit->val);
                precursor->right = visit;
                visit = visit->left;
            }else if (precursor->right == visit) {
                precursor->right = NULL;
                visit = visit->right;
            }else {
                cout << "ERROR" << endl;
                return ;
            }
        }
    }
    //查找前驱结点
    TreeNode *find_precursor(TreeNode *node) {
        if (node == NULL || node->left == NULL) return NULL;
        TreeNode *temp = node->left;
        while (temp->right != NULL && temp->right != node)
            temp = temp->right;
        return temp;
    }
};

int main() {

    return 0;
}
