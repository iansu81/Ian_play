#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {
        int ans;
        unordered_map<char, int> record;

        // 每次當蒐集到兩個字母的時候就+2
        for(const auto& c: s) {
            record[c]++;
            if( (record[c] % 2) == 0 ) ans += 2;
        }

        // 確定看有沒有frequency 是奇數的
        int num_odd_char = 0;
        for(const auto e:record) {
            if(e.second % 2 != 0) num_odd_char++;
        }

        // 如果要palindrome的話, 奇數只能取一個
        if(num_odd_char) ans += 1;

        return ans;
    }
};

// 另一種想法:頻率不是奇數就是偶數, 所以蒐集完頻率之後看有幾個字母的frequency是奇數, 
// 這時候只要把字母的數量減掉這個奇數的數量+1(palindrome可以有一個奇數)
// Ans = s.size() - (有幾個字母的frequency是奇數) + 1(如果有奇數的話)