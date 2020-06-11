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

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *currentNode = head;
        ListNode *nodeBehind = nullptr;
        ListNode *nodeAhead = currentNode->next;
        while( currentNode != nullptr)
        {
            currentNode->next = nodeBehind;
            nodeBehind = currentNode;
            currentNode = nodeAhead;

            if(nodeAhead != nullptr)
            {
                nodeAhead = nodeAhead->next;
            }
        return nodeBehind;
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
    view = sol.reverseList(view);
    while( view != nullptr )
    {
        cout << view->val << endl;
        view = view->next;
        cout << "Dammm" << endl;
    }


}