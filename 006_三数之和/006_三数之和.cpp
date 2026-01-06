
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; ++i) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int left = i + 1;
			int right = n - 1;
			while (left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				if (sum == 0) {
					result.push_back({ nums[i],nums[left],nums[right] });
					while (left < right && nums[left] == nums[left + 1]) ++left;
					while (left < right && nums[right] == nums[right-1]) --right;
					++left;
					--right;
				}
				else if(sum < 0) {
					++left;
				}
				else{
					--right;
				}
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> result = solution.threeSum(nums);
	for (auto& triplet : result) {
		for (int num : triplet)
			cout << num << " ";
		cout << endl;
	}
}

//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> result;
//        int n = nums.size();
//        //排序
//        sort(nums.begin(), nums.end());
//        //遍历数组---i < n-2确保在固定第一个数后，至少还有两个位置可以放另外两个数
//        for (int i = 0; i < n - 2; ++i) {
//            //如果当前元素和前一个元素相同直接跳过，避免重复三元组
//            if (i > 0 && nums[i] == nums[i - 1]) continue;
//            //使用双指针寻找其他两个元素
//            int left = i + 1;
//            int right = n - 1;
//            while (left < right) {
//                int sum = nums[i] + nums[left] + nums[right];
//                if (sum == 0) {
//                    result.push_back({ nums[i],nums[left],nums[right] });
//                    //跳过重复元素
//                    while (left < right && nums[left] == nums[left + 1]) ++left;
//                    while (left < right && nums[right] == nums[right - 1]) --right;
//                    //移动指针
//                    ++left;
//                    --right;
//                }
//                else if (sum < 0) {
//                    ++left;
//                }
//                else {
//                    --right;
//                }
//            }
//        }
//        return result;
//    }
//};
