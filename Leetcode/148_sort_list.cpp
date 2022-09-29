#include <memory>


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
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        shared_ptr<ListNode> slow;
        shared_ptr<ListNode> fast;

        while(fast != nullptr && fast->next != nullptr) {
            slow=slow->next;
            fast = fast->next->next;
        }
        


        return mergeList(left, right);
        
    }


    ListNode* mergeList(ListNode* l1, ListNode* l2) {

        shared_ptr<ListNode> head = make_shared<ListNode>(0);
        shared_ptr<ListNode> tmp = head;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                tmp->next = l1;
                tmp = tmp->next;
                l1 = l1->next;
            }
            else{
                tmp->next = l2;
                tmp = tmp->next;
                l2 = l2->next;
            }
        }
        if(l1) {
            tmp->next = l1;
        }
        else if(l2) {
            tmp->next = l2;
        }

        return head->next;

    }
};