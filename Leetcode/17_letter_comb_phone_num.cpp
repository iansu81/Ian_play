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
        if(digits.size() == 0)
        {
            return result;
        }
        // 建立一個table去求所有按鍵的字母
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
        string tmp_record;
        helper(table, digits, 0, result, tmp_record);
        return result;
    }
    // 利用int l去遍歷所有digit,每次push進去之後記得再pop讓record recover
    void helper(unordered_map<char, vector<char>> &table, string digits, int l, vector<string> &result, string &record){
        if(l >= digits.size())
        {
            result.push_back(record);
            return;
        }
        // 這邊記得不要在一個for loop去遍歷digit, 只要考慮index l,不然會出現"dd, de,df, ee,ff" 這種重複
        for(const auto& c: table[digits[l]])
        {
            record.push_back(c);
            helper(table, digits, l+1, result, record);
            record.pop_back();
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