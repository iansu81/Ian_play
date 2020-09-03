#include <iostream>
#include <unordered_map>
#include <limits.h>

using namespace std;
// 這一題的解法其實是sliding window
// 用兩個iterator來紀錄最短的string, 從l=0, r=0 開始, 先把r一個一個往右移
// 當target string的字全部都找到的時候, 就嘗試把左邊再往右移, 試試看可不可以縮短

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> target_map;
        string ans = "";
        // 一開始先遍歷target string,紀錄每個char出現幾次
        for(const auto& c: t)
        {
            target_map[c]++;
        }
        int left = 0;
        int right = 0;
        // 利用count來紀錄現在找到target string 裡面幾個char, 當count == target_string.len()的時候,代表所有文字都找到了
        int count = 0;
        int target_len = t.size();

        // 紀錄最短的string可以多短
        int minlen = INT_MAX;
        while(right < s.size())
        {
            // 當每次移動right index的時候, 就把那個char在map裡面的數字-1, 負的代表有多的, 
            if(--target_map[s[right]] >= 0) count++;
            while( count == target_len )
            {
                if(minlen > (right - left + 1))
                {
                    minlen = (right - left + 1);
                    // 注意substr用法！！！ string.substr（起始index, 長度） 而不是string.substr(左index,右index)
                    ans = s.substr(left, minlen);
                    
                }

                if(++target_map[s[left]] > 0) count--;
                left++;
            }
            right++;

            
        }
        return ans;
    }
};



int main(){

    string test = "ab";
    string target = "a";
    Solution sol;
    string ans = sol.minWindow(test, target);
    cout << "Ans: " << ans << endl;




}