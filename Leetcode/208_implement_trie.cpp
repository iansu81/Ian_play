

class Trie {
private:
    struct TrieNode {
        TrieNode(): is_end(false), children(26, nullptr) {}
        ~TrieNode() {
            for(auto child: children) {
                if(child) delete child;
            }
        }

        // is_end 用來確定這個node是不是一個單字的結尾
        bool is_end;
        vector<TrieNode*> children;
    };
public:
    // 建立一個dummy root來當起始點 
    Trie() {
        root = unique_ptr<TrieNode>(new TrieNode());
    }
    
    void insert(string word) {
        TrieNode* temp = root.get();
        for(char c: word) {

            // 注意!!! 一定要先確定是不是null_ptr, 不然會new多個trieNode()
            if(temp->children[c-'a'] == nullptr) temp->children[c-'a'] = new TrieNode();
            temp = temp->children[c-'a'];
        }
        // 做到最後一個character, 要把這個TrieNode的is_end設成true!
        temp->is_end = true;
    }
    // Search 跟start with 最大的差別就是search的結尾一定要是一個字
    bool search(string word) {
        TrieNode* result = DFS(word);
        return (result != nullptr) && (result->is_end);
    }
    
    bool startsWith(string prefix) {
        TrieNode* result = DFS(prefix);
        return (result != nullptr);
    }

    TrieNode* DFS(string word) {
        TrieNode* temp = root.get();
        for(const auto& c : word) {
            if(temp->children[c - 'a'] == nullptr) return nullptr; 
            temp = temp->children[c - 'a'];
        }
        return temp;
    }


    std::unique_ptr<TrieNode> root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */