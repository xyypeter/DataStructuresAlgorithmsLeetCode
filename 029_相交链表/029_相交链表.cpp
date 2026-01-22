#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA != pB) {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }
        return pA;
    }
};

int main(){
    // 公共部分
    ListNode* c1 = new ListNode(8);
    c1->next = new ListNode(10);
    // 链表 A: 3 → 7 → 8 → 10
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = c1;
    // 链表 B: 99 → 1 → 8 → 10
    ListNode* headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = c1;
    Solution s;
    ListNode* res = s.getIntersectionNode(headA, headB);
    if (res)
        cout << "相交节点值: " << res->val << endl;
    else
        cout << "不相交" << endl;
    return 0;
}

