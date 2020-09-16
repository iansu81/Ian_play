#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        unordered_map<char, vector<char>> table(
            {
                {'2', {'a', 'b', 'c'}},
                {'3', {'d', 'e', 'f'}},
                {'4', {'g', 'h', 'i'}},
                {'5', {'j', 'k', 'l'}},
                {'6', {'m', 'n', 'o'}},
                {'7', {'p', 'q', 'r', 's'}},
                {'8', {'t', 'u', 'v'}},
                {'9', {'w', 'x', 'y','z'}}
            }
        );

        return result;
    }
    void helper(unordered_map<char, vector<char>> &table, string digit, vector<string> &result, string &record){
        if(record.size() == digit.size())
        {
            result.push_back(record);
            return;
        }
        for(const auto& d: digit)
        {
            for(const auto& c: table[d])
            {
                
                record.push_back(c);
                helper(table)
            }
        }
    }

};

int main()
{
    string test = "23";
    Solution sol;
    vector<string> result = sol.letterCombinations(test);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ',';
    }
}