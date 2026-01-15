#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;//记录历史最低价
        int maxProfit = 0;     //记录最大利润
        for (int price : prices) {
            //更新最低买入价
            minPrice = min(minPrice, price);
            //更新最大利润
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};

int main(){
    Solution s;
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    cout << "最大利润为: " << s.maxProfit(prices) << endl;
    return 0;
}


