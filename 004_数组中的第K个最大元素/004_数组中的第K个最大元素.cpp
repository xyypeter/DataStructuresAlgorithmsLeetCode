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


