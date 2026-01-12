#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            int need = target - nums[i];
            if (mp.count(need)) return { mp[need],i };
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;

    Solution s;
    vector<int> result = s.twoSum(nums, target);

    cout << result[0] << " " << result[1] << endl; // 输出 0 1
    return 0;
}
