#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


// 方法1: 利用一個hashtable 去存第一個linked list 的pointer, 
// 接著遍歷另一個linked list確定有沒有相同的
// Note: 不可以同時間遍歷兩個linked list, 不然有可能其中某一個linkedlist已經遍歷完了, 另一個還沒到達相同的node

// 方法2: 2 pointer, 每一步都把兩個pointer移到下一個, 等到一個pointer已經走到nullptr, 把這個pointer移到另一個linked list一開始的頭
// ex: 當headA 走到nullptr的時候, 把這個pointer移到當初headB的頭, headB走到尾巴的時候把它移到當初headA的頭, 
// 這樣兩個pointer在遇到intersection前, 遍歷過的不重疊的node會是相同的 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    unordered_set<ListNode*> record;
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA != nullptr){
            record.insert(headA);
            headA = headA->next;

        }
    
        while(headB != nullptr){
            if(record.count(headB)) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};