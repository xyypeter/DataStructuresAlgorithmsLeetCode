#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> result;
    vector<string> path;
    void backtrack(const string& s, int start) {
        if (path.size() == 4) {     // 如果已经有 4 段
            if (start == s.size()) {// 且字符串刚好用完
                string ip = path[0];// 拼接成 IP 地址
                for (int i = 1; i < 4; i++) {
                    ip += "." + path[i];
                }
                result.push_back(ip);
            }
            return;
        }
        for (int i = start; i < s.size() && i < start + 3; i++) {// 尝试切 1~3 位作为一段
            if (s[start] == '0' && i > start) break;             // 前导 0 剪枝
            string segment = s.substr(start, i - start + 1);     // 取子串并转成整数
            int num = stoi(segment);
            if (num > 255) break;                                // 超出 IP 范围
            path.push_back(segment);                             // 做选择
            backtrack(s, i + 1);// 递归处理下一段
            path.pop_back();// 撤销选择
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return result;
        backtrack(s, 0);
        return result;
    }
};

int main(){
    Solution s;
    string input = "25525511135";
    vector<string> res = s.restoreIpAddresses(input);
    for (const auto& ip : res) {
        cout << ip << endl;
    }
    return 0;
}
