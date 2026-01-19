#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int m = matrix.size();   //行
        int n = matrix[0].size();//列
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        while (top <= bottom && left <= right) {
            //1.从左到右(上边)
            for (int j = left; j <= right; j++)
                result.push_back(matrix[top][j]);
            top++;
            //2.从上到下(右边)
            for (int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;
            //3.从右到左(下边)
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    result.push_back(matrix[bottom][j]);
                bottom--;
            }
            //4.从下到上(左边)
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;
            }
        }
        return result;
    }
};

int main(){
    vector<vector<int>> matrix = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };
    Solution s;
    vector<int> res = s.spiralOrder(matrix);
    for (int x : res)
        cout << x << " ";
    return 0;
}


