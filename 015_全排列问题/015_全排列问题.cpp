#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used;
    void backtrack(vector<int>& nums) {
        //递归终止条件:排列长度等于nums长度
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        //选择列表
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums);        //进入下一层
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);
        backtrack(nums);
        return result;
    }
};

int main(){
    vector<int> nums = { 1, 2, 3 };
    Solution s;
    vector<vector<int>> ans = s.permute(nums);
    for (auto& v : ans) {
        for (int x : v) cout << x << " ";
        cout << endl;
    }
    return 0;
}
