/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


// Recursive
class Solution {
public:
    void helper(Node* root, vector<int>& result) {
        result.push_back(root->val);
        for(const auto& n: root->children) {
            helper(n, result);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> result;
        if(root == nullptr) return result;
        helper(root, result);
        return result;
    }

};



// Iterative

class Solution {
public:

    vector<int> preorder(Node* root) {
        vector<int> result;
        if(root == nullptr) return result;

        stack<Node*> record;
        record.push(root);
        while( !record.empty() ) {

            Node* n = record.top();
            result.push_back(n->val);
            record.pop();

            // 注意這邊一定要從後面跑回來, 不然左邊的元素就會被壓在stack最下面, 最後被跑到,
            // 這樣就會變成root->right->left
            for(int i = (n->children.size() - 1); i >=0 ; i--) {
                record.push(n->children[i]);
            }

        }
        return result;
    }

};

