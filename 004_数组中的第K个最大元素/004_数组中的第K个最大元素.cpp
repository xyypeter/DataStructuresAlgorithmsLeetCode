#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left == right) {
            return nums[left];
        }
        int index = partition(nums,left,right);
        if (k == index) {
            return nums[k];
        }else if (k < index) {
            return quickSelect(nums, left, index - 1, k);
        }else {
            return quickSelect(nums, index + 1, right, k);
        }
    }
    int partition(vector<int>& nums, int left, int right) {
        int povit = nums[right];
        int i = left;
        for (int j = left; j < right; ++j) {
            if (nums[j] < povit) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 3, 2, 1, 5, 6, 4 };
    int k = 2;
    cout << solution.findKthLargest(nums, k) << endl;  // 输出 5

    nums = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
    k = 4;
    cout << solution.findKthLargest(nums, k) << endl;  // 输出 4

    return 0;
}


//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        // k = nums.size() - k 用来转换成从小到大查找
//        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
//    }
//    // 快速选择算法
//    int quickSelect(vector<int>& nums, int left, int right, int k) {
//        if (left == right) {
//            return nums[left];
//        }
//        // 选择一个基准元素,进行分区
//        int pivotIndex = partition(nums, left, right);
//        // 如果k是基准元素的位置，直接返回
//        if (k == pivotIndex) {
//            return nums[k];
//        }
//        else if (k < pivotIndex) {//K在左边递归左边部分
//            return quickSelect(nums, left, pivotIndex - 1, k);
//        }
//        else {
//            return quickSelect(nums, pivotIndex + 1, right, k);
//        }
//    }
//    //分区操作，返回基准元素的最终位置
//    int partition(vector<int>& nums, int left, int right) {
//        int pivot = nums[right];//选择最后一个元素作为基准
//        int i = left;           //i是小于基准元素的区间的边界
//        // 遍历数组，将小于基准的元素移动至左边
//        for (int j = left; j < right; ++j) {
//            if (nums[j] < pivot) {
//                //保持小于基准元素在左边
//                swap(nums[i], nums[j]);
//                i++;
//            }
//        }
//        // 将基准元素放到正确的位置
//        swap(nums[i], nums[right]);
//        return i;
//    }
//};