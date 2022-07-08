


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> record;
        ListNode *tmp = head;
        while(tmp != nullptr) {
            if(record.count(tmp)) return tmp;
            record.insert(tmp);
            tmp = tmp->next;

        }
        return nullptr;
        
    }
};