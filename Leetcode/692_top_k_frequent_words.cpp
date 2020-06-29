#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> data;
        for (auto &str : words)
        {
            auto it = data.find(str);
            if(it != data.end())
            {
                data[str] += 1;
            }
            
        }
            

        }
    }
};

int main()
{
    vector<string> 

}