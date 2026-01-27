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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;      //使用虚拟头结点方便处理头结点被删除的情况
        ListNode* curr = head;  //curr用来遍历链表
        ListNode* prev = &dummy;//prev指向"已确认且不重复"的最后一个节点
        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                int duplicateVal = curr->val;
                while (curr && curr->val == duplicateVal) {
                    curr = curr->next;
                }
                prev->next = curr;
            }else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode* reversed = s.deleteDuplicates(head);
    ListNode* p = reversed;
    while (p != nullptr) {
        cout << p->val << "->";
        p = p->next;
    }
    cout << endl;
    return 0;
}
