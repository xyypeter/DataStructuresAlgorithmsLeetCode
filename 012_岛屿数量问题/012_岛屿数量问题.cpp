#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int rows = grid.size();   //行
        int cols = grid[0].size();//列
        int count = 0;
        //四个方向:上、下、左、右
        int dx[4] = { 1,-1,0,0 };
        int dy[4] = { 0,0,1,-1 };
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    count++;          //表示发现一座岛屿  
                    grid[i][j] == '0';//标记为已被访问
                    queue<pair<int, int>> q;
                    q.push({ i,j });
                    //使用BFS扩展整座岛屿
                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        int x = cur.first;
                        int y = cur.second;
                        for (int k = 0; k < 4; ++k) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == '1') {
                                grid[nx][ny] = '0';
                                q.push({ nx,ny });
                            }
                        }
                    }
                }
            
            }
        }
        return count;
    }
};

int main(){
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    Solution s;
    cout << s.numIslands(grid) << endl;  // 输出：3

    return 0;
}

