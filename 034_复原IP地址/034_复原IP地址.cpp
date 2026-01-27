#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int n = s.length();
        if (n < 4 || n>12)return result;
        for (int i = 1; i <= 3 && i < n; i++) {                 // 第一个点在i后面
            for (int j = i + 1; j <= i + 3 && j < n; j++) {     // 第二个点在j后面
                for (int k = j + 1; k <= j + 3 && k < n; k++) { // 第三个点在k后面
                    // 此时字符串被切成四段: [0,i), [i,j), [j,k), [k,n)
                    string seg1 = s.substr(0, i);
                    string seg2 = s.substr(i, j-i);
                    string seg3 = s.substr(j, k-j);
                    string seg4 = s.substr(k, n-k);
                    if (isValid(seg1) && isValid(seg2) && isValid(seg3) && isValid(seg4)) {
                        result.push_back(seg1 + "." + seg2 + "." + seg3 + "." + seg4);
                    }
                }
            }
        }
        return result;
    }
private:
    bool isValid(const string& segment) {
        int len = segment.length();
        if (len == 0 || len > 3) return false;
        if (segment[0] == '0' && len > 1) return false;
        int num = stoi(segment);
        return num >= 0 && num <= 255;
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
