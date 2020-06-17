#include <iostream>
using namespace std;
//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* nodeBehind = &dummy;
        
        // 把nodeBehind 移到m node前一個
        for(int i = 0; i < m - 1; i++ )
        {
            nodeBehind = nodeBehind-> next;
        }
        
        ListNode* curNode = nodeBehind->next;
        // 紀錄m前一個node（之後要接到n node）
        ListNode* preHead = nodeBehind;
        // 紀錄mnode（之後要接到n node 下一個）
        ListNode* tail = curNode;
        
        // 開始reverse node 
        for(int i = m ; i <= n ; i++)
        {
            ListNode* nodeAhead = curNode->next;
            curNode->next = nodeBehind;
            nodeBehind = curNode;
            curNode = nodeAhead;
        }
        // 把m node 前一個接到n node 
        preHead->next = nodeBehind;
        // 把m node接到 n node 下一個
        tail->next = curNode;
        return dummy.next;
    }
};
int main() 
{
    ListNode test1(5);
    ListNode test2(4, &test1);
    ListNode test3(3, &test2);
    ListNode test4(2, &test3);
    ListNode test5(1, &test4);
    ListNode *view = &test5;

    Solution sol;
    view = sol.reverseBetween(view, 2, 3);
    for(int i = 0; i < 5; i++)
    {
        cout << view->val << "->" ;
        view = view->next;
    }




}