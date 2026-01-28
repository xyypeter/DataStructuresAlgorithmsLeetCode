#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 确保 nums1 是较短的数组,提高二分查找效率
        // 原因是:二分的范围是 [0, m]，m 越小，越安全、越高效
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        while (left <= right) {
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;
            // nums1 左边的最大值
            // 如果 i == 0，说明 nums1 左边没元素，用 -∞ 兜底
            int leftMax1 = (i == 0) ? INT_MIN : nums1[i - 1];
            // nums1 右边的最小值
            // 如果 i == m，说明 nums1 右边没元素，用 +∞ 兜底
            int rightMin1 = (i == m) ? INT_MAX : nums1[i];
            // nums2 左边的最大值
            int leftMax2 = (j == 0) ? INT_MIN : nums2[j - 1];
            // nums2 右边的最小值
            int rightMin2 = (j == n) ? INT_MAX : nums2[j];
            // 判断当前分割是否满足“中位数条件”,左半部分所有元素 ≤ 右半部分所有元素
            if (leftMax1 <= rightMin2 && leftMax2 <= rightMin1) {
                if ((m + n) % 2 == 0) {
                    return (max(leftMax1, leftMax2) +min(rightMin1, rightMin2)) / 2.0;
                }else {
                    return max(leftMax1, leftMax2);
                }
            }else if (leftMax1 > rightMin2) {// i 太大，往左走
                right = i - 1;
            }else {// i 太小，往右走
                left = i + 1;
            }
        }
        return 0.0; // 理论上不会到这里
    }
};


int main(){
    vector<int> nums1{ 1,2,5,6 };
    vector<int> nums2{ 3,4,7,8,9 };
    Solution s;
    double result = s.findMedianSortedArrays(nums1,nums2);
    cout << "result=" << result;
}
