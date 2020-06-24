1. 因為要access to randon key in O(1) -> hashtable
2. 要把最後面的element 刪掉 -> list or vector
3. Add/move an entry to the front of LRU Cache in O(1) -> list


class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity; 
    }
    
    int get(int key) {
        unordered_map<int, list<pair<int, int> >::iterator>::const_iterator got = LRU_map.find (key);

        // 如果不在裡面, 直接return -1;
        if ( got == LRU_map.end() ){
            return -1;
        }
        else{
            // 找到的話,把iterator記錄下來
            list<pair<int, int>>::iterator it = got->second;
            // 把節點移到最前面
            record.splice(record.begin(), record, it);
            return it->second;
            
        }
            
    }
    
    void put(int key, int value) {
        unordered_map<int, list<pair<int, int> >::iterator>::const_iterator got = LRU_map.find (key);
        
        // 如果key已經存在在裡面
        if( got != LRU_map.end()){
            // 更新值
            got->second->second = value;
            // 把這一項移到最前面
            record.splice(record.begin(), record, got->second);
            return;
            
        }
        // key 不存在list裡面
       
        // 當capacity已經滿的時候
        if(record.size() == _capacity){
            // 把他從hashtable刪掉
            int key = record.back().first;
            LRU_map.erase(key);

            // 從list裡面刪掉
            record.pop_back();
            
        }

        // 把元素插到list最前面
        record.push_front(make_pair(key, value));
        // key 對應到list最前面的pointer
        LRU_map[key] = record.begin();
        
    }
private:
    // 第一個是key, 第二個是pointer用來訪問list 中結點
    unordered_map<int, list<pair<int, int>>::iterator> LRU_map;
    int _capacity = 0;
    // 第一個是key, 第二個是value
    list< pair<int, int> > record;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

