#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//定义单链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(nullptr) {}
};

//反转链表的迭代法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;//下一个元素
        ListNode* curr = head;   //当前元素
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

// 测试链表反转
int main() {
    //创建测试链表 1->2->3->4->5->nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    //创建反转链表对象
    Solution sol;
    ListNode* reversed = sol.reverseList(head);
    //输出上述列表的结果
    ListNode* p = reversed;
    while (p != nullptr) {
        cout << p->val << "->";
        p = p->next;
    }
    cout << endl;
    return 0;
}

