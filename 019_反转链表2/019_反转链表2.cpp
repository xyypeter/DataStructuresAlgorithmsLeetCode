#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0), next{ nullptr } {}
    ListNode(int x) :val(x), next{ nullptr } {}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //虚拟头节点
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        //1.移动pre到Left前一个节点
        for (int i = 1; i < left; i++) {
            pre = pre->next;//1
        }
        //2.开始反转
        ListNode* cur = pre->next;//2
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = cur->next;//3             //4
            cur->next = temp->next;    //2->4          //2->5  
            temp->next = pre->next;    //3->2          //4->3 
            pre->next = temp;          //1->3->2->4->5 //1->4->3->2->5
        }
        return dummy.next;
    }
};

// 辅助函数：打印链表
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // 构建链表 1->2->3->4->5
    ListNode* head = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    cout << "原链表: ";
    printList(head);
    Solution s;
    head = s.reverseBetween(head, 2, 4);
    cout << "反转后: ";
    printList(head);
    return 0;
}

