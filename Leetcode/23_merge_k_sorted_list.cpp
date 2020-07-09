
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    public:
        ListNode *mergeKLists(vector<ListNode *> &lists)
        {
            ListNode* dummy;
            auto comp = [] (ListNode* A, ListNode* B){ return A->val > B->val; };
            priority_queue<ListNode*, vector<ListNode*>, decltype(comp)>
                q (comp);
            for(int i = 0; i< lists.size(); ++i)
            {
                q.push(lists[i]);
            }
            ListNode* temp = dummy;
            while( !q.empty() )
            {
                temp->next = q.top();
                q.pop();
                temp = temp->next;
                if(temp->next) q.push(temp->next);
            }

            return dummy->next;
        }
};


int main(){
    ListNode n1_1(5);
    ListNode n1_2(4, &n1_1);
    ListNode n1_3(1, &n1_2);

    ListNode n2_1(4);
    ListNode n2_2(3, &n2_1);
    ListNode n2_3(1, &n2_2);

    ListNode n3_1(6);
    ListNode n3_2(2, &n3_1);


    vector<ListNode*> test{&n1_3, &n2_3, &n3_2};

    Solution sol;
    ListNode *temp = sol.mergeKLists(test);

    // ListNode *temp = &n1_3;
    while(temp != nullptr)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }

}