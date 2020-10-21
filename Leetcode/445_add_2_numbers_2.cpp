#include <vector>
#include <stack>


using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 利用兩個stack, 先把元素push進去這兩個stack,然後每次都拿最上面的出來運算,這樣就可以確保是從最右邊做到最左邊
        stack<int> n1;
        stack<int> n2;
        ListNode* temp = l1;
        while(temp != NULL)
        {
            n1.push(temp->val);
            temp = temp->next;
        }
        temp = l2;
        while(temp != NULL)
        {
            n2.push(temp->val);
            temp = temp->next;
        }
        int carry = 0;
        ListNode* dummy_head = new ListNode();

        // 最後別忘了如果是5+5=10, carry＝1的edge case,所以最後要確認carry是不是＝＝0
        while( !n1.empty() || !n2.empty() || carry!=0 )
        {
            int val_1 = 0;
            int val_2 = 0;
            if(!n1.empty())
            {
                val_1 = n1.top();
                n1.pop();
            }
            if(!n2.empty())
            {
                val_2 = n2.top();
                n2.pop();
            }
            int sum = val_1 + val_2 + carry;
            carry = sum / 10;
            ListNode* newNode = new ListNode( sum % 10);
            newNode->next = dummy_head->next;
            dummy_head->next = newNode;
        }
        return dummy_head->next;
    }
};