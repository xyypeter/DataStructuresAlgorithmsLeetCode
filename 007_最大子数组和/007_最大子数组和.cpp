#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0];  // 初始化最大和为第一个元素
        int current_sum = nums[0];  // 当前子数组的和
        // 从第二个元素开始遍历
        for (int i = 1; i < n; ++i) {
            // 状态转移方程：选择当前元素自己，或者加上前一个子数组的和
            current_sum = max(nums[i], current_sum + nums[i]);
            // 更新最大和
            max_sum = max(max_sum, current_sum);
        }
        return max_sum;
    }
};

int main() {
    Solution solution;
    // 示例 1
    vector<int> nums1 = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    cout << "最大子数组和: " << solution.maxSubArray(nums1) << endl; // 输出 6
    // 示例 2
    vector<int> nums2 = { 1 };
    cout << "最大子数组和: " << solution.maxSubArray(nums2) << endl; // 输出 1
    // 示例 3
    vector<int> nums3 = { 5, 4, -1, 7, 8 };
    cout << "最大子数组和: " << solution.maxSubArray(nums3) << endl; // 输出 23
    return 0;
}
