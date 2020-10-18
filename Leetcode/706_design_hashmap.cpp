class MyHashMap
{
public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        vector<int> temp(1000, -1);
        for (int i = 0; i < 1000; i++)
            m_.push_back(temp);
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        m_[(key % 1000)][key/1000] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        return m_[(key % 1000)][key / 1000];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        m_[(key % 1000)][key / 1000] = -1;
    }
private:
    vector<vector<int>> m_;
};