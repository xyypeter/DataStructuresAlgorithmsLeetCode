#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand(time(NULL));// 随机数种子，确保每次运行基准不同
        quick_sort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
private:
    void quick_sort(vector<int>& nums, int left, int right) {
        // 检查数组是否有序
        bool ordered = true;
        for (int i = left; i < right; i++) {
            if (nums[i] > nums[i + 1]) {
                ordered = false;
                break;
            }
        }
        // 检查数组是否有序
        if (ordered) return;
        // 数组无序，则开始分区且递归排序
        int i = partition(nums, left, right);
        quick_sort(nums, left, i - 1);
        quick_sort(nums, i + 1, right);
    }
    // 分区函数，返回基准元素的最终位置
    int partition(vector<int>& nums, int left, int right) {
        int i = left + rand() % (right - left + 1);// 随机选择基准
        int pivot = nums[i];                       // 随机选择的基准元素
        swap(nums[i], nums[left]);                 // 把基准放到左侧
        i = left + 1;                              // 左边界(跳过基准元素)
        int j = right;                             // 右边界
        while (true) {
            while (i <= j && nums[i] < pivot) i++; // 寻找大于基准的元素
            while (i <= j && nums[j] > pivot) j--; // 寻找小于基准的元素
            if (i >= j) break;                     // 如果i与j交错，退出循环
            swap(nums[i], nums[j]);                // 交换满足条件的元素
            i++;
            i--;
        }
        swap(nums[left], nums[j]);                 // 把基准元素放到正确的位置,j指向最后一个小于基准的元素,所以此处一定是j
        return j;
    }
};

int main(){
    Solution solution;
    // 示例 1
    vector<int> nums1 = { 5, 2, 3, 1 };
    vector<int> result1 = solution.sortArray(nums1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;  // 输出: 1 2 3 5
    // 示例 2
    vector<int> nums2 = { 5, 1, 1, 2, 0, 0 };
    vector<int> result2 = solution.sortArray(nums2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;  // 输出: 0 0 1 1 2 5
    return 0;
}


