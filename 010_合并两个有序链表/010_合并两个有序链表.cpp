#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int x) :val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while (list1 != nullptr && list2 != nullptr) {
            ListNode** pp = (list1->val < list2->val) ? &list1 : &list2;
            curr->next = *pp;
            curr = curr->next;
            *pp = (*pp)->next;
        }
        curr->next = (list1) ? list1 : list2;
        return head->next;
    }
};

int main() {
    Solution sol;
    // ===== 测试用例 1 =====
    // list1 = 1 -> 3 -> 5
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);
    // list2 = 2 -> 4 -> 6
    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);
    ListNode* head = sol.mergeTwoLists(list1, list2);
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
    // 期望输出：1 -> 2 -> 3 -> 4 -> 5 -> 6
    return 0;
}

