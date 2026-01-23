#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;//从word1到空字符串只有删除操作
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;//从空字符串到word2只有插入操作
        //开始填表
        for (int i = 1; i <= m; i++) {              // 遍历word1的所有字符
            for (int j = 1; j <= n; j++) {          // 遍历word2的所有字符
                if (word1[i - 1] == word2[j - 1]) { // 比较 word1 的第 i-1 个字符 和 word2 的第 j-1 个字符
                    dp[i][j] = dp[i - 1][j - 1];    // 如果 word1 的第 i 个字符 和 word2 的第 j 个字符相同,不需要对这两个字符进行任何操作
                }else {
                    dp[i][j] = min({
                        dp[i - 1][j] + 1,           // 删除操作
                        dp[i][j - 1] + 1,           // 插入操作
                        dp[i - 1][j - 1] + 1        // 替换操作
                        });
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    Solution s;
    cout << s.minDistance("horse", "ros") << endl;      // 3
    cout << s.minDistance("intention", "execution") << endl; // 5
    return 0;
}

