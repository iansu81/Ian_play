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
        ListNode *temp = head;
        ListNode *nextNode = nullptr;
        ListNode *prev = temp->next;
        while( temp != nullptr)
        {
            if(temp != nullptr){
                cout << "In temp: " << temp->val << endl;
            }
            // if( prev != nullptr)
            // {
            //     cout << "In temp: " << temp->val << endl;
            // }
            // if (next != nullptr)
            // {
            //     cout << "In temp: " << temp->val << endl;
            // }

            temp->next = nextNode;
            // cout << "111 " << endl;
            nextNode = temp;
            // cout << "222 " << endl;
            temp = prev;
            // cout << "333 " << endl;
            // if(temp == nullptr){
            //     cout << "TEMP next is null" << endl;
            // }
            // cout << "999" << endl;
            if(prev != nullptr)
            {
                // cout << "555" << endl;
                prev = prev->next;
                // cout << "666" << endl;
            }
            // prev = prev->next;
            
            // cout << "444 " << endl;
        }
        // cout << "888"<< endl;
        return nextNode;
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