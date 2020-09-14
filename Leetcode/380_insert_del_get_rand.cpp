class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    // 插入的時候, 如果已經存在就return false,否則就push到vector最後面, 然後update hash map
    bool insert(int val)
    {
        if(record.count(val)) return false;
        elements.push_back(val);
        record[val] = elements.size() - 1;
        return true;

    }
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    // 移除的時候, 先把要移除數值的index 記錄下來, 把vector最後面一個數字的index update成這個index, 再把這個要移除的數字swap到vector最後面移除掉, 然後也從hash map 移除
    bool remove(int val)
    {
        if(!record.count(val)) return false;
        int index_to_remove = record[val];
        record[elements.back()] = index_to_remove;
        swap(elements.back(), elements[index_to_remove]);
        elements.pop_back();
        record.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int rand = random() % (elements.size());
        return elements[rand];
    }
private: 
    // 用一個hash_map來記錄目前所有的值, key: 值, value: 值在vector 的index 
    unordered_map<int, int> record;
    vector<int> elements;
    

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */