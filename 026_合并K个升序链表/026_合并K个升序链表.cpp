#include <iostream>
#include <string>
#include <vector>
#include <queue>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //小顶堆:val小的优先
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        //1.将每个链表的头节点放入堆中
        for (ListNode* node : lists) {
            if (node) pq.push(node);
        }
        //2.创建虚拟头节点，方便操作
        ListNode  dummy(0);
        ListNode* tail = &dummy;
        //3.不断从堆中取出最小节点
        while (!pq.empty()) {
            //3.1取出最小堆的顶部节点
            ListNode* node = pq.top();
            pq.pop();
            //3.2开始链接节点
            tail->next = node;
            tail = tail->next;
            //3.3把下一个节点放进堆中
            if (node->next) {
                pq.push(node->next);
            }
        }
        return dummy.next;
    }
private:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};

int main(){
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));
    vector<ListNode*> lists = { l1, l2, l3 };
    Solution s;
    ListNode* res = s.mergeKLists(lists);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
