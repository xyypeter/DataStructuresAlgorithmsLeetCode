#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastpos;
        int left = 0;
        int maxLen = 0;
        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            if (lastpos.count(c) && lastpos[c] >= left) {
                left = lastpos[c] + 1;
            }
            lastpos[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }
    }
};

int main() {
    Solution sol;
    string s1 = "abcabcbb";
    cout << sol.lengthOfLongestSubstring(s1) << endl; // 输出 3
    string s2 = "bbbbb";
    cout << sol.lengthOfLongestSubstring(s2) << endl; // 输出 1
    string s3 = "pwwkew";
    cout << sol.lengthOfLongestSubstring(s3) << endl; // 输出 3
    return 0;
}

//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        //1.定义唯一键值的哈表表
//        unordered_map<char, int> lastpos;
//        //2.定义左边界和最大长度
//        int left = 0;
//        int maxLen = 0;
//        //3.使用right遍历字符串
//        for (int right = 0; right < s.size(); ++right) {
//            //取出字符
//            char c = s[right];
//            //判断哈希表中是否含有此字符,如果存在移动左边界
//            if (lastpos.count(c) && lastpos[c] >= left) {
//                left = lastpos[c] + 1;
//            }
//            //如果不存在,更新哈希表
//            lastpos[c] = right;
//            //更新最大长度
//            maxLen = max(maxLen, right - left + 1);
//        }
//        return maxLen;
//    }
//};
