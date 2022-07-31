#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;



class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> result;

        // 如果p 比s長, 那一定沒有答案
        if(s.size() < p.size()) return result;

        // 利用兩個vector來記錄頻路以及做anagram的比較
        vector<int> s_freq(26, 0);
        vector<int> p_freq(26, 0);

        // 先把p 的頻率紀錄好
        for(int i = 0; i < p.size(); i++) {
            s_freq[s[i] - 'a']++;
            p_freq[p[i] - 'a']++;
        }

        // 如果兩個頻率的vector一樣, 代表s的index 0 開始的substring就是一個anagram
        if(s_freq == p_freq ) result.push_back(0);

        // 接下來開始fix size的sliding window
        for(int i = p.size(); i < s.size(); i++) {
            // 先把原本substring裡面最前面的char踢掉
            s_freq[s[i-p.size()]-'a']--;
            // 增加最信的char的frequency
            s_freq[s[i]-'a']++;

            // 如果跟p 相等就把substring的頭push進result
            if(s_freq == p_freq) result.push_back(i-p.size()+1);
        }
        return result;
        
    }
};

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    Solution sol;
    vector<int> ans = sol.findAnagrams(s, p);
    for(const auto& a: ans) {

        std::cout << a << ',';
    }
    std::cout << endl;
}