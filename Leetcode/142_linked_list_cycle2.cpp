/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Sol 1:
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_set<ListNode*> record;
//         ListNode *tmp = head;
//         while(tmp != nullptr) {
//             if(record.count(tmp)) return tmp;
//             record.insert(tmp);
//             tmp = tmp->next;

//         }
//         return nullptr;
        
//     }
// };


#include <iostream>

using namespace std;

// Sol 2:
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;


        // 第一步: 確定有沒有環以及找出相交的點
        while( fast != nullptr && fast->next != nullptr ) {

            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }

        // 如果fast 或下一步是nullptr代表沒有環
        if(fast == nullptr || fast->next == nullptr) return nullptr;


        // 在相遇點 slow走了K步, fast走了2K步, 此時fast比slow多走了一個環, 代表一圈是K步, 
        // 假設相遇點到環的起點距離n, 此時fast距離繞一圈回到環的起始點還要走K-n步, 如果此時從head開始走到環起點也是K-n步
        // 接下來把slow移到head, fast還在相交的點, 此時兩個每次都只走一步, 相交的點就是環的起點

        slow = head;

        while(slow != fast) {

            slow = slow->next;
            fast = fast->next;
        }

        return slow;
        
    }
};



int main() {
    ListNode a(3);
    ListNode b(2);
    ListNode c(0);
    ListNode d(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &b;
    Solution sol;
    ListNode* ans = sol.detectCycle(&a);

    std::cout << "Ans: " << ans->val << std::endl;

    return 0;

}