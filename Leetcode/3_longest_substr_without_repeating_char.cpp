#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 利用一個vector去紀錄目前所有字母最大的index
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            // 當找到相同的字母的時候就要把之前的那個char移除掉, 把start update成那個index 其實就是把那個字母移除掉
            // ex: 第一個a出現在index 2 , 又出現在index 4, 當iterate 到index 4的時候
            // maxLen = 4-2 = 2 也就是只取index 3 & 4
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};