#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <list>
#include <unordered_map>

using namespace std;

struct CacheNode
{
    int key;
    int value;
    int freq;
    // 用來記錄在frequcy_list中node所在的位置
    list<int>::iterator it;
};


class LFUCache {
    private:
        int capacity_;
        // Key就是key, value是CacheNode,用來記錄真的資料
        unordered_map<int, CacheNode> data;
        //用來紀錄頻率,同頻率的用一個list去紀錄, 當滿得時候把list最後面踢掉, key是各個frequency, value是在這個frequency下有哪些key
        unordered_map<int, list<int> > frequency_list;
        //紀錄最小的frequency, 當capacity滿的時候,用來決定要踢哪個出去
        int min_frequency;
        //每當get或put的時候, 用touch 來update frequency and frequency list.
        void touch(CacheNode &node)
        {
            int prev_freq = node.freq;

            //把這一項從舊的frequecy list移除
            frequency_list[prev_freq].erase(node.it);
            node.freq++;

            // 當min_freq的list只有一個element 而且我們要touch 那個element的時候, 必須要把這個frequency從frequncy的map移除掉
            if (frequency_list[prev_freq].empty() && prev_freq == min_frequency)
            {
                frequency_list.erase(prev_freq);
                min_frequency++;
            }
            //把這個node移到新的frequency中的list中最前面,然後再將node的iterator指向這個node
            frequency_list[node.freq].push_front(node.key);
            node.it = frequency_list[node.freq].begin();
        }

    public:
        LFUCache(int capacity) {
            capacity_ = capacity;
            min_frequency = 0;
        }

        int get(int key) {
            //看元素有沒有在裡面,如果有就touch這個node增加freq跟移到新的freq最前面
            auto it = data.find(key);
            if( it == data.end()) return -1;
            touch(data[key]);
            return data[key].value;
        }

        void put(int key, int value) {
            if(capacity_ == 0) return;

            // 如果key已經存在資料裡面, update val, touch就好
            auto it = data.find(key);
            if( it != data.end() )
            {
                data[key].value = value;
                touch(data[key]);
                return;
            }

            //如果capacity已經滿了,必須要把min_freq的list中的最後一個元素丟掉才能放新的
            if(data.size() == capacity_)
            {
                int pre_key = frequency_list[min_frequency].back();
                frequency_list[min_frequency].pop_back();
                data.erase(pre_key);
            }

            //創建一個新的node, 新的元素的freq一定是1
            int frequency = 1;
            min_frequency = frequency;
            frequency_list[frequency].push_front(key);
            CacheNode newNode;
            newNode.key = key;
            newNode.value = value;
            newNode.freq = frequency;
            newNode.it = frequency_list[frequency].begin();
            data[key] = newNode;      
        }

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */