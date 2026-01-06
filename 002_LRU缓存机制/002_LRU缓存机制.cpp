#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class LRUCache {
    //定义双链表的节点
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int key, int value) :key(key), value(value), prev(nullptr), next(nullptr) {}
    };
    Node* head;//虚拟头结点
    Node* tail;//虚拟尾结点
    //将节点加入头部
    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    //删除某个节点
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    //将节点移动至头部
    void moveToHead(Node* node) {
        removeNode(node);//先删除，后添加
        addToHead(node);
    }
    //删除尾部节点(LRU)
    Node* removeTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
private:
    int capatity;                   //定义LRU缓存容量
    unordered_map<int, Node*> cache;//定义哈希表
public:
    LRUCache(int capatity) :capatity(capatity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    void put(int key, int value) {
        if (cache.count(key)) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);//将节点移动至头部
        }else {
            Node* node = new Node(key, value);
            cache[key] = node;
            addToHead(node);
            if (cache.size() > capatity) {
                Node* tailNode = removeTail();
                cache.erase(tailNode->key);
                delete tailNode;
            }
        }
    }
    int get(int key) {
        if (cache.count(key)) {
            Node* node = cache[key];
            moveToHead(node);//将节点移动至头部
            return node->value;
        }
        else {
            return -1;
        }
    }
};


int main(){
    LRUCache lru(2);            //创建缓存容量为2的LRU
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl; // 1
    lru.put(3, 3);              // 淘汰 key=2
    cout << lru.get(2) << endl; // -1
    lru.put(4, 4);              // 淘汰 key=1
    cout << lru.get(1) << endl; // -1
    cout << lru.get(3) << endl; // 3
    cout << lru.get(4) << endl; // 4
}

