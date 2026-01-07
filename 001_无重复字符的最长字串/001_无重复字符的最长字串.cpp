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
        return maxLen;
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

