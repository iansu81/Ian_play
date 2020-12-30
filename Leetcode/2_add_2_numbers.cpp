#include <vector>
#include <iostream>
#include <climits>
#include <unordered_map>

using namespace std;


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=new ListNode(0);
        ListNode* head=temp;
        int numSav=0;
        int carry=0;
        int x=0;
        int y=0;
        while(l1 || l2){
            x = (l1 != NULL) ? l1->val : 0;
            y = (l2 != NULL) ? l2->val : 0;
            numSav=x+y+carry;
            carry=0;
            if(l1 !=NULL){
                l1=l1->next;
            }
            if(l2 !=NULL){
                l2=l2->next;
            }
            
            carry=numSav/10;
            numSav=numSav % 10;
            temp->next=new ListNode(numSav);
            temp=temp->next;
        }
        if(carry != 0){
            temp->next=new ListNode(carry);
            temp=temp->next;  
            
        }
        return head->next;
    }
};