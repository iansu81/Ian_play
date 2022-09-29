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

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 利用雙指針: 第一個指針先走n步, 然後此時第二個指針從頭開始走, 等到第一個指針走到尾巴, 
// 第二個指針剛好走道距離尾巴n個node距離的地方


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        ListNode* tmp2 = head;

        for(int i = 0; i < n; i++){
            tmp = tmp->next;
        }

        // 如果n的跟list的node數量一樣的話, 因為我們無法拿到head之前的node資訊,
        // 所以忽略第一個node是最好的做法 
        if(tmp == nullptr) return  head->next;

  
        // 這邊check不用temp!=nullptr的原因是, 我們希望後開始的指針, 停留在要移除的node前一個
        // 這樣就可以直接tmp2->next=tmp2->next->next移除掉, 所以用tmp->next可以提前一步結束while loop 
        while(tmp->next != nullptr) {
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        tmp2->next = tmp2->next->next;

        return head;
    }
};



int main() {
    ListNode a(1);
    // ListNode b(2);
    // ListNode c(0);
    // ListNode d(4);
    // a.next = &b;
    // b.next = &c;
    // c.next = &d;
    // d.next = &b;
    Solution sol;
    ListNode* ans = sol.removeNthFromEnd(&a, 1);

    while(ans != nullptr){

        std::cout << "Ans: " << ans->val << std::endl;
        ans = ans->next;
    }

    

    return 0;

}