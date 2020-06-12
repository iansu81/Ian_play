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
        ListNode* curNode = head;
        ListNode *nodeAhead = curNode->next;
        ListNode* nodeBehind = nullptr;
        ListNode* tail = nullptr;
        ListNode* prehead;
        for(int i = 1; i <= n; i++)
        {
            // cout << "curr" << i << endl;
            if( i == m){
                tail = curNode;
                cout << "tail: " << tail->val << endl;
                prehead = nodeBehind;
                cout << "prehead: " << prehead->val << endl;
            }
            // else if( i == n )
            // {
                
            // }
            // cout << "currNode: " << curNode->val << endl;

            curNode->next = nodeBehind;
            nodeBehind = curNode;
            curNode = nodeAhead;
            if(nodeAhead)
            {
                nodeAhead = nodeAhead->next;    
            }
            
            if( i == n)
            {
                // cout << "curNode" << curNode->val << endl;
                // cout << "nodeAhead" << nodeAhead->val << endl;
                cout << "Tail" << tail->val << endl;
                prehead->next = nodeBehind;
                tail->next = curNode;
    
            }


            
        }
        return head;
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
        cout << view->val << endl;
        view = view->next;
    }




}