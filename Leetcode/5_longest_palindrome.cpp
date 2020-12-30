#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int get_length(int left, int right, string s){
        int l = left;
        int r = right;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            --l;
            ++r;
            
        }
        return r -l - 1;    
        
        
    } 
    string longestPalindrome(string s) {
        int len = 0;
        int start = 0;
        for(int i = 0; i < s.size(); i++){
            // Case 1: aba
            // Case 2: abba
            // 兩種情況都要考慮
            int cur = max(get_length(i,i, s), get_length(i,(i+1), s));
            if(cur > len){
                len = cur;
                start = i - (len-1)/2;
            }

        }
        return s.substr(start, len);

        
    }

};