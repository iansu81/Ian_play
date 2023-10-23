/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        // 如果input已經是nullptr, 直接return nullptr!
        if(node == nullptr) return nullptr;
        

        // 用一個hashmap來記錄原本的node跟複製完的node original->copied
        unordered_map<Node*, Node*> m;

        // 遍歷所有的neighbors
        function<void(Node*)> dfs = [&](Node* n){
            m[n] = new Node(n->val);
            for(auto v: n->neighbors){
                if(!m.count(v)) dfs(v);
                m[n]->neighbors.push_back(m[v]);
            }
            return m[n];
        };
        dfs(node);
        return m[node];
    }
};