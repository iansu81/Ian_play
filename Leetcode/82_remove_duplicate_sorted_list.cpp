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
    ListNode* deleteDuplicates(ListNode* head) {

        // 先建立一個dummy node, 把這個dummy node 的下一個指向list 的head
        ListNode* dummy = new ListNode(0, head);

        // 用一個pointer來連接接下來的node
        ListNode* temp = dummy;


        while(head != nullptr) {

            // 當head跟head的元素相同時, 必須要一直移動head直到head停在相同元素的最後一個
            if(head->next != nullptr && head->val == head->next->val) {
                while(head->next != nullptr && head->val == head->next->val) head = head->next;
                // 因為所有的相同元素都不要, 所以直接比temp的下一個指向head的next
                // 不這樣做的話, 用temp去指向head, 如果最後處理到的幾個元素是相同元素, 會無法把temp尾巴指向nullptr
                temp->next = head->next;
            }
            // 如果head指向的元素沒有重複, 就直接移動temp即可
            else
                temp = temp->next;

            head = head->next;
        }
        return dummy->next;
        
    }
};