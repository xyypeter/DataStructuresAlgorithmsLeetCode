#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		if (n < 2) return s;
		int start=0;
		int maxLen = 1;
		for (int i = 0; i < n; i++) {
		    //奇数回文子串，中心扩展函数
			centerExpand(s, i, i, start, maxLen);
			//偶数回文子串，中心扩展函数
			centerExpand(s, i, i+1, start, maxLen);
		}
		return s.substr(start, maxLen);
	}
private:
	void centerExpand(const string& s, int left, int right, int& start, int& maxLen) {
		int n = s.size();
		while (left >= 0 && right < n && s[left] == s[right]) {
			left--;
			right++;
		}
		int len = right - left - 1;
		if (len > maxLen) {
			maxLen = len;
			start = left + 1;
		}
	}
};

int main() {
	Solution sol;
	cout << sol.longestPalindrome("babad") << endl;
	cout << sol.longestPalindrome("cbbd") << endl;
}

