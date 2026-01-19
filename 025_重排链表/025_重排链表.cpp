#include <iostream>
#include <string>
#include <vector>
#include <queue>
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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        //1.找到链表的中点
        ListNode* slow = head;
        ListNode* fast = head;
        //使用快慢指针的方式找到中点
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //2.反转链表的后半部分
        ListNode* second = slow->next;
        slow->next = nullptr;
        second = reverseList(second);
        //3.交换合并两个链表
        ListNode* first = head;
        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }

    }
private:
    //反转链表的辅助函数
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};

int main(){
    // 创建链表 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    s.reorderList(head);
    // 输出结果：1 -> 5 -> 2 -> 4 -> 3
    ListNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    return 0;
}

