#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int x) :val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) :val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 虚拟头结点
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        // fast 先走 n 步
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        // fast 和 slow 一起走
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        // 删除倒数第 n 个节点
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete; 
        return dummy.next;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode* reversed = s.removeNthFromEnd(head,2);
    ListNode* p = reversed;
    while (p != nullptr) {
        cout << p->val << "->";
        p = p->next;
    }
    cout << endl;
    return 0;
    
}

