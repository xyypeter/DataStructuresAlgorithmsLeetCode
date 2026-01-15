#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //终止条件
        if (root == nullptr || root == p || root == q)  return root;
        //左右子树查找
        TreeNode* left  = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        //如果p和q分别在左右子树
        if (left && right) return root;
        //否则返回非空的那一侧
        return left ? left:right;
    }
};

int main(){
    /*
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    Solution s;
    TreeNode* p = root->left;               // 节点 5
    TreeNode* q = root->left->right->right; // 节点 4
    TreeNode* lca = s.lowestCommonAncestor(root, p, q);
    cout << "最近公共祖先是: " << lca->val << endl;
    return 0;
}

