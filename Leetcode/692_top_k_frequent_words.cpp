#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
    public:
        vector<string> topKFrequent(vector<string> &words, int k)
        {
            vector<string> ans;
            unordered_map<string, int> data;
            // 利用一個unordered_map 去紀錄所有字的頻率
            for (auto &str : words) data[str]++;

            // 利用一個priority_queue 來排序所有的字跟頻率
            // Note:這邊必須要注意的是比較的時候 
            // 1. 要再插入得時候就把不需要的部分拿掉,不然之後處理很麻煩
            // 2. 頻率較高的要擺在priority_queue 的後面, 但是string 字符比較高的要擺在後面ex： i 要擺在love 後面
            // 因為之後要把頻率高的排在第一個, 但是i 又要在love前面, 所以要小心Ａ.first 必須< B.first

            auto cmp = [](pair<string, int> A, pair<string, int> B) {
                if( A.second == B.second)
                    return A.first < B.first;

                return A.second > B.second;
            };
            priority_queue<pair<string, int>, vector< pair<string, int>>, decltype(cmp)> ordered_element(cmp);
            for(const auto element: data)
            {
                ordered_element.push({element.first, element.second});
                if(ordered_element.size() > k) ordered_element.pop();
            }

            // 把他們全部都塞到vector去,但是順序這時候是反的, 所以必須reverse.
            while (!ordered_element.empty())
            {
                cout << ordered_element.top().first << "," << ordered_element.top().second << endl;
                ans.push_back(ordered_element.top().first);
                ordered_element.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }

};

int main()
{
    vector<string> test{"i", "love", "leetcode", "i", "love", "coding"};
    Solution sol;
    vector<string> back = sol.topKFrequent(test, 2);
    for(int i = 0 ; i < back.size(); i++)
    {
        cout << back[i] << endl;
    }
}