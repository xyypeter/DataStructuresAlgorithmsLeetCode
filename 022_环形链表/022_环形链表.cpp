#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;
        ListNode* slow = head;//满指针
        ListNode* fast = head;//快指针
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;      //满指针每次走一步
            fast = fast->next->next;//快指针每次走两步
            if (slow == fast) {     //如果快指针追上慢指针，说明存在环
                return true;
            }
        }
        return false;
    }
};

int main(){
    // 构建链表 1 -> 2 -> 3 -> 4 -> 5 -> 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    // 创建环：节点 6 指向节点 3
    head->next->next->next->next->next->next = head->next->next;
    Solution s;
    if (s.hasCycle(head)) {
        cout << "链表有环" << endl;
    }else {
        cout << "链表无环" << endl;
    }
    return 0;
}


