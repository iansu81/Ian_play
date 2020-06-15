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
        
        for(int i = 0; i < m - 1; i++ )
        {
            nodeBehind = nodeBehind-> next;
        }
        ListNode* curNode = nodeBehind->next;
        ListNode* preHead = nodeBehind;
        ListNode* tail = curNode;
        
        for(int i = m ; i <= n ; i++)
        {
            ListNode* nodeAhead = curNode->next;
            curNode->next = nodeBehind;
            nodeBehind = curNode;
            curNode = nodeAhead;
        }
        preHead->next = nodeBehind;
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