#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;


// 兩種解法：
// 1. heap
// 2. quick select

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for(const auto &e: nums)
        {
            freq[e]++;
        }
        auto comp = [](const pair<int, int> &A, const pair<int, int> &B)
        {
            return A.second > B.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp) > q(comp);
        for (auto it = freq.begin(); it != freq.end(); ++it){
            q.push(make_pair(it->first, it->second));
            if(q.size() > k) q.pop();
        }
        vector<int> result;
        while(!q.empty())
        {
            result.push_back(q.top().first);
            q.pop();
        }
        return result;
    }
};



int main()
{
    vector<int> test{1, 1, 1, 2, 2, 3};
    Solution sol;
    vector<int> result = sol.topKFrequent(test, 2);
    for(const auto &e: result)
    {
        cout << e << ',';
    }
    cout << endl;


}