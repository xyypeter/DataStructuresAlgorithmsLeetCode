#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) {
                tails.push_back(x);
            }else {
                *it = x;
            }
        }
        return tails.size();
    }
};


class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        // dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度
        // 初始时，每个元素自身至少可以构成一个长度为1的子序列
        vector<int> dp(n, 1);
        // 存储最终结果，初始化为1（至少长度为1）
        int ans = 1;
        // 外层循环：遍历每个元素，计算以该元素结尾的最长递增子序列长度
        for (int i = 0; i < n; i++) {
            // 内层循环：检查 i 之前的所有元素
            for (int j = 0; j < i; j++) {
                // 如果 nums[j] < nums[i]，说明 nums[i] 可以接在 nums[j] 后面
                if (nums[j] < nums[i]) {
                    // 更新 dp[i] 的最大值
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            // 更新全局最大值
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        // tails 数组用于记录每个长度的递增子序列的最小尾部元素
        vector<int> tails;
        // 遍历数组中的每个元素 x
        for (int x : nums) {
            // 在 tails 中使用二分查找，找到第一个不小于 x 的位置
            auto it = lower_bound(tails.begin(), tails.end(), x);
            // 如果没有找到合适的位置，说明 x 比所有现有尾部值都大，需扩展 LIS 的长度
            if (it == tails.end()) {
                tails.push_back(x);  // 将 x 加入 tails，表示扩展了一个递增子序列
            }else {
                // 否则，更新该位置的尾部值，保证当前子序列尾部值最小
                *it = x;  // 用 x 替换掉比它大的尾部元素
            }
        }
        // 返回 tails 数组的大小，即最长递增子序列的长度
        return tails.size();
    }
};

int main(){
    vector<int> nums = { 10,9,2,5,3,7,101,18 };
    Solution s;
    cout << s.lengthOfLIS(nums) << endl; // 输出 4
    return 0;
}

