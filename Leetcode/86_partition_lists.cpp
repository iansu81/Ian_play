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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


// 建立兩個sub-linked_list一個存比x小的, 一個存比x大的
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode *p1 = new ListNode(-1);
        ListNode *p2 = new ListNode(-1);
        ListNode *tmp1 = p1, *tmp2 = p2;

        while(head != nullptr) {
            if(head->val < x) {
                tmp1->next = head;
                tmp1 = tmp1->next;
            }
            else{
                tmp2->next = head;
                tmp2 = tmp2->next;
            }

            // 這邊很tricky, 因為走完上面那一步之後, tmp1/tmp2, 會跟head指向同一個object,
            // 在倒數兩個object,如果沒有清乾淨最後面的listnode讓他指向nullptr,順序會亂掉
            ListNode *tmp = head->next;
            head->next = nullptr;
            head = tmp;
        }

        tmp1->next = p2->next;

        return p1->next;
        
    }
};