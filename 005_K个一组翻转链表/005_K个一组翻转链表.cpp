
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* curr = head;
		int count = 0;
		while (curr) {
			count++;
			curr = curr->next;
		}
		if (count < k) return head;
		//翻转K个节点
		ListNode* prev = nullptr;
		ListNode* next = nullptr;
		curr = head;
		for (int i = 0; i < k; i++) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		if (next) {
			head->next = reverseKGroup(next, k);
		}
		return prev;
	}
};

int main(){
	// 创建一个示例链表：1 -> 2 -> 3 -> 4 -> 5
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	Solution solution;
	ListNode* result = solution.reverseKGroup(head, 2);

	// 打印结果
	while (result) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
	return 0;
}


