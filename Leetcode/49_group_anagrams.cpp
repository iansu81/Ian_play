

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


// 1. 建立一個hash map, key是sort之後的string, value是在所有在strings裡sort之後是相同string的index
// ex: [aet, ate] => sort之後都是aet => hash[aet] = [0,1]
// 2. 之後遍歷所有在hash map, 把sort之後相同的string 都push到vector裡再push 到ans的vector裡面

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> str_record;
        for(int i = 0 ; i < strs.size() ; i++)
        {
            string sorted_str = strs[i];
            sort(sorted_str.begin(), sorted_str.end());
            str_record[sorted_str].push_back(i);
        }
        for(auto kv: str_record)
        {
            vector<string> sub_ans;
            for(int i = 0; i < kv.second.size(); i ++)
            {
                sub_ans.push_back(strs[kv.second[i]]);
            }
            ans.push_back(sub_ans);
        }
        return ans;
    }
};


int main()
{
    vector<string> test_strs {  "eat", "tea", "tan", "ate", "nat", "bat" };
    Solution sol;
    vector<vector<string>> result = sol.groupAnagrams(test_strs);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << ',';
        }
        cout << endl;
    }
}