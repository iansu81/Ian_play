
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if(head == NULL)
        {
            return NULL;
        }

        //Round 1: 先在每個node後面copy一個完全相同的node
        // ex: 1->2->3     =====>> 1->1'->2->2'->3->3'
        Node* cur  = head;
        while(cur != NULL )
        {
            Node* newNode = new Node(cur->val);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = cur->next->next;
        }
        // Round 2: 把每個copied Node的random pointer都接好, 這邊注意因為cur->random可能是NULL,一定要加一個if
        // 但是cur->next不可能是NULL(因為有1',2'...)
        cur = head;
        while(cur != NULL){
            if(cur->random != NULL)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        // Round 3: 把copied 的node挑出來, 順便把原本的node list恢復成原樣
        cur = head;
        Node* dummy = new Node(0);
        Node* copyNode = dummy;
        while(cur != NULL)
        {
            copyNode->next = cur->next;
            cur->next = cur->next->next;
            copyNode = copyNode->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};