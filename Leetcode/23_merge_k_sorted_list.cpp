
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
            if(lists.size() == 0)
            {
                return nullptr;
            }
            //建立一個dummy node ,記得要new,不然離開這程式, pointer就消失
            ListNode* dummy = new ListNode();
            
            //建立一個priority_queue, 比較各個node中最大的
            auto comp = [] (ListNode* A, ListNode* B){ return A->val > B->val; };
            priority_queue<ListNode*, vector<ListNode*>, decltype(comp)>
                q (comp);

            //把各個vector中最大的先push 進去priority_queue
            //注意這裡可以能會有[[]]的情形,所以在push進去之前,必須要先確定她是不是nullptr
            for(int i = 0; i< lists.size(); ++i)
            {
                if(lists[i]) q.push(lists[i]);
            }
            
            //每次都先把最小的拿出來然後把最小那個list中下一個push進去priority_queue.
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