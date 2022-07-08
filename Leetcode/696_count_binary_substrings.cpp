
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <queue>
#include <algorithm>


using namespace std;


class Solution {
public:
    int countBinarySubstrings(string s) {

        // 1. Group 1 and 0 separately, and then count how many 0s or 1s in each section.
        // For example "0110001111" will be [1, 2, 3, 4].

        // 2. 題目說要consecutively, 所以0101這樣不算
        // 3. The number of valid substring will be the minimum number of 0 and 1 in 2 consecutive section.
        //     For example "0001111", will be min(3, 4) = 3, ("01", "0011", "000111")

        // 利用Prev來記錄前面的section有幾個0 or 1
        // Cur 來記錄現在的0 或 1有幾個
        int prev = 0;
        int cur = 1;
        int result = 0;
        for(int i = 1; i < s.size(); i++) {

            if(s[i] != s[i-1]) {
                // 忽略第一區
                if(prev != 0) {
                    result += min(prev, cur);
                }
                prev = cur;
                cur = 1;
            }
            else cur++;
        }

        // 處理最後一個section
        result += min(prev,cur);
        return result;
    }
};

int main() {

    string test = "10101";
    Solution sol;
    std::cout << "Ans: " << sol.countBinarySubstrings(test);



}