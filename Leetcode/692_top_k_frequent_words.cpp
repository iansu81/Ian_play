#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
class Solution
{
    public:
        vector<string> topKFrequent(vector<string> &words, int k)
        {
            vector<string> ans;
            unordered_map<string, int> data;
            for (auto &str : words)
            {
                auto it = data.find(str);
                if(it != data.end())
                {
                    data[str] += 1;
                }
                else{
                    data[str] = 1;
                }
            }
            auto cmp = [](pair<string, int> A, pair<string, int> B) {
                if( A.second == B.second)
                    return A.first > B.first;

                return A.second > B.second;
            };
            priority_queue<pair<string, int>, vector< pair<string, int>>, decltype(cmp)> ordered_element(cmp);
            for(const auto element: data)
            {
                ordered_element.push(make_pair(element.first, element.second));
            }
            while (ordered_element.size() > 0)
            {
                if (ordered_element.size() > k)
                {
                    ordered_element.pop();
                }
                else{
                    ans.push_back(ordered_element)
                }
            }

                return ans;
                

        }

};


int main()
{
    vector<string> test{"i", "love", "leetcode", "i", "love", "coding"};
    Solution sol;
    sol.topKFrequent(test, 2);
}