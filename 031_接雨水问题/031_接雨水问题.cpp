#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//当前位置能接水:
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int left = 0, right = height.size() - 1;  // 左右指针，分别从数组两端开始
        int left_max = 0, right_max = 0;          // 记录左边和右边当前遇到的“最高柱子”
        int water_trapped = 0;                    // 最终累计的接水总量
        while (left <= right) {                   // 当左右指针还没有交叉时，继续处理
            if (height[left] < height[right]) {   // 如果左边柱子比右边矮,那么:当前能接多少水，只由 left_max 决定
                if (height[left] >= left_max) {   // 如果当前柱子 >= 左边最高柱子,说明这个位置本身不能接水,只能更新 left_max
                    left_max = height[left];    
                }else {                           // 当前位置可以接水,水量 = 左边最高柱子 - 当前高度
                    water_trapped += left_max - height[left];
                }
                left++;
            }else {                               // 否则：右边柱子 <= 左边柱子
                if (height[right] >= right_max) { // 如果当前柱子 >= 右边最高柱子,说明：这个位置不能接水，只更新 right_max
                    right_max = height[right];    
                }else {                           // 否则：当前位置可以接水,水量 = 右边最高柱子 - 当前高度
                    water_trapped += right_max - height[right];
                }
                right--;
            }
        }
        return water_trapped;
    }
};

int main(){
    Solution s;
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << "Total water trapped: " << s.trap(height) << endl;  // Output: 6
    return 0;
}

//O(n)的解决方案如下:相对好理解
//height        : 0 1 0 2 1 0 1 3 2 1 2 1
//maxL          : 0 0 1 1 2 2 2 2 3 3 3 3 (从左向右编写记录左边界最大高度)
//maxR          : 3 3 3 3 3 3 3 2 2 2 1 0 (从右向左编写记录右边界最大高度) 
//min[maxL,maxR]: 0 0 1 1 2 2 2 2 2 2 1 0
//min-height    : 0 0 1 0 1 2 1 0 0 1 0 0 结果为6，负数直接表示0                 