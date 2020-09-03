#include <iostream>
#include <unordered_map>
#include <limits.h>

using namespace std;


class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> target_map;
        string ans = "";
        for(const auto& c: t)
        {
            target_map[c]++;
        }
        int left = 0;
        int right = 0;
        int count = 0;
        int target_len = t.size();
        int minlen = INT_MAX;
        while(right < s.size())
        {
            if(--target_map[s[right]] >= 0) count++;
            while( count == target_len )
            {
                if(minlen > (right - left + 1))
            }

            
        }
    }
};



int main(){





}