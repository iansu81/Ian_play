#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
typedef pair<string, int> pi;
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
            auto cmp = [](pi A, pi B){
                if( A.second == B.second) return A.first > B.first;

                return A.second > B.second;
            };
            priority_queue< pi, vector<string, pi>, decltype(cmp)> ordered_element(cmp);
            for(const auto element: data)
            {
                ordered_elemnt.push(make_pair(data.first, data.seconf) );
            }

            return ans;
                

        }

};

int main()
{
    vector<string> test{"i", "love", "leetcode", "i", "love", "coding"};
    Solution sol;

    
}