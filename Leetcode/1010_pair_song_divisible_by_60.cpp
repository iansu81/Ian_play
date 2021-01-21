
// 類似2 sum, 只是這邊要用一個unordered_map來記 key: 值, val: 出現的次數

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int ans = 0;
        unordered_map<int, int> record;
        for (const auto &e : time)
        {
            int tmp = e % 60;
            // 這邊有edge case要注意 當數＝＝60的時候要特別處理一下
            if (tmp == 0)
                ans += record[0];
            if (record.count(60 - tmp))
                ans += record[60 - tmp];
            record[tmp]++;
        }
        return ans;
    }
};