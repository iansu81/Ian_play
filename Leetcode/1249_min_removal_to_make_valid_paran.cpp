#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int close = count(s.begin(), s.end(), ')');
        int open = 0;
        string ans; 
        for(const auto& c: s)
        {
            if(c == '('){
                if(open == close) continue;
                open++
            }
            else if(c == ')')
            {

            }
        }

    }
};


int main() {
    string test1 = "lee(t(c)o)de)";
    string test2 = "a)b(c)d";
    string test3 = "))((";
    string test4 = "(a(b(c)d)";

    Solution sol;
    sol.minRemoveToMakeValid(test1);
}