#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string nums1, string nums2) {
        int i = nums1.size() - 1;//指向nums1的末尾
        int j = nums2.size() - 1;//指向nums2的末尾
        int carry = 0;           //标志进位
        string result;
        while (i >= 0 || j >= 0 || carry) {  //只要 还有数字没算完 或 还有进位，就不能停。
            int x = (i >= 0) ? nums1[i] - '0' : 0;
            int y = (j >= 0) ? nums2[j] - '0' : 0;
            int sum = x + y + carry;
            result.push_back(sum % 10 + '0');//当前位
            carry = sum / 10;                //更新进位
            i--;
            j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution s;
    cout << s.addStrings("123", "789") << endl;   // 912
    cout << s.addStrings("999", "1") << endl;     // 1000
    cout << s.addStrings("0", "0") << endl;       // 0
}
