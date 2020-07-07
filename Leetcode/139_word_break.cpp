#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    //記錄以前查找過的所有紀錄, 避免重複查找
    unordered_map<string, bool> record;

public:
    //先把vector弄成unordered_set方便查詢
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return wordBreak(s, dict);

    }
    bool wordBreak(string s, unordered_set<string> &dict)
    {
        //如果是以前有查過的字,直接查找
        if ( record.count(s) ) return record[s];
        //如果是以前沒找過,但是在dictionary 裡面的,紀錄並return true
        if( dict.count(s) ) return record[s] = true;
        for(int i = 0 ; i < s.size(); i++)
        {
            //開始拆字 ex: ”leetcode“拆成
            // 1. "", "leetcode"
            // 2. "l", "eetcode"....
            string left = s.substr(0,i);
            string right = s.substr(i);
            if( dict.count(right) && wordBreak(left, dict) )
            {
                return record[s] = true;
            }
        }
        return record[s] = false;
    }

};


int main()
{
    string test = "leetcode";
    vector<string> dict{"leet", "code" };
    Solution sol;
    cout << sol.wordBreak( test, dict);
}