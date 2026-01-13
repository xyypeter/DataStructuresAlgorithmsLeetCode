#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;            //nums1有效部分末尾
        int j = n - 1;            //nums2末尾
        int k = m + n - 1;        //nums1总末尾
        while (i >= 0 && j >= 0) {//从后向前合并
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            }else {
                nums1[k--] = nums2[j--];
            }
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main(){
    vector<int> nums1 = { 1,2,3,0,0,0 };
    vector<int> nums2 = { 2,5,6 };
    Solution s;
    s.merge(nums1, 3, nums2, 3);
    for (int x : nums1) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}


