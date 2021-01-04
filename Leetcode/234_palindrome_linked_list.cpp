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


// 利用一個double ended queue 去紀錄所有的元素, 
// 每次從前面跟後面各pop一個元素比較, 看是不是相同的
// 加上一個edge case去處理奇數個元素
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        deque<int> record;
        ListNode* temp = head;
        while(temp != nullptr){
            record.push_back(temp->val);
            temp = temp->next;
        }

        deque <int> :: iterator it; 
        while(!record.empty())
        {
            if(record.size() < 2){
                return true;
            }
            if( record.front() != record.back())
            {
                return false;
            }
            else
            {
                record.pop_front();
                record.pop_back();
            }
        }
        return true;
            
    }
};