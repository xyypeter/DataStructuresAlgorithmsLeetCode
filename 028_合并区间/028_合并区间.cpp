#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;
        //1.按照区间起点排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        //2.放入第一个区间
        res.push_back(intervals[0]);
        //3.遍历后续区间
        for (int i = 1; i < intervals.size(); i++) {
            
            int curStart = intervals[i][0];//当前区间起始位置
            int curEnd = intervals[i][1];  //当前区间结束位置 
            int lastEnd = res.back()[1];   //结果中的最后一个区间
            if (curStart <= lastEnd) {     //判断重叠
                res.back()[1] = max(lastEnd, curEnd);
            }else {                        //不重叠直接加入结果
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main(){
    vector<vector<int>> intervals = {
       {1,3}, {2,6}, {8,10}, {15,18}
    };
    Solution s;
    vector<vector<int>> res = s.merge(intervals);
    for (auto& v : res) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    return 0;
}

