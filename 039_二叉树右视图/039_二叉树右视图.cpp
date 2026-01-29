#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}  
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();//获取当前层的节点数量
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (i == levelSize - 1) {
                    result.push_back(node->val);
                }
                // 将子节点加入队列
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        return result;
    }
};

int main(){
    // 构建测试树: [1,2,3,null,5,null,4]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution solution;
    vector<int> result = solution.rightSideView(root);

    cout << "Right Side View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // 清理内存
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
