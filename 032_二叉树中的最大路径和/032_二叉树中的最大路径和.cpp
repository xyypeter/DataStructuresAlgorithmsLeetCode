#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :val(), left(nullptr), right(nullptr) {}
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans = INT_MIN;       //全局最大路径和
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root) {                    //求取最大路径和
        if (!root) return 0;
        int left = max(0, dfs(root->left));      //求左子树的最大单边贡献
        int right = max(0, dfs(root->right));    //求右子树的最大单边贡献
        ans = max(ans, root->val + left + right);//情况2:以当前节点为最高点的路径
        return root->val + max(left, right);     //情况1:返回给父节点单边最大路径
    }
};

int main(){
    /*
      -10
      /  \
     9   20
        /  \
       15   7
    */
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution s;
    cout << s.maxPathSum(root) << endl; // 输出 42
    return 0;
}

