#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, n = version1.size(), m = version2.size();
        while (i < n || j < m) {
            long long num1 = 0, num2 = 0;
            while (i < n && version1[i] != '.') num1 = num1 * 10 + (version1[i++] - '0');
            while (j < m&& version2[j] != '.') num2 = num2 * 10 + (version2[j++] - '0');
            if (num1 != num2) return num1 > num2 ? 1 : -1;
            i++; j++;
        }
        return 0;
    }
};

int main() {
    Solution solution;

    // 测试用例
    vector<pair<string, string>> testCases = {
        {"1.01", "1.001"},  // 0
        {"1.0", "1.0.0"},   // 0
        {"0.1", "1.1"},     // -1
        {"1.0.1", "1"},     // 1
        {"7.5.2.4", "7.5.3"}, // -1
        {"1.2", "1.10"},    // -1
        {"3.0.4.10", "3.0.4.2"}, // 1
    };

    for (auto& testCase : testCases) {
        string version1 = testCase.first;
        string version2 = testCase.second;
        int result = solution.compareVersion(version1, version2);

        cout << "compareVersion(\"" << version1 << "\", \"" << version2 << "\") = ";
        cout << result << endl;
    }

    return 0;
}

