#include <iostream>

using namespace std;

// Every time we meet a '[', we treat it as a subproblem so call our recursive function to get the content in that '[' and ']'. After that, repeat that content for 'num' times.
// Every time we meet a ']', we know a subproblem finished and just return the 'word' we got in this subproblem.
// Please notice that the 'pos' is passed by reference, use it to record the position of the original string we are looking at.
// 每次我們碰到一個'[',就把它視為一個新的子問題, 所以用recursive的方法去解接下來到'[', ']'的string, 之後我們把這個子string加Ｎ次加到主要的string裡面去,
// 每次我們碰到一個']', 就知道這個子問題已經解完了,所以return word,
// 碰到字母就把它加到word,
// 碰到digit就把目前的數字＊10加上去

class Solution
{
public:
    string decodeString(string s) {
        int pos = 0;
        return decode_helper( pos, s);
    }
    string decode_helper(int &pos, string s)
    {
        int num = 0;
        string word = "";
        for(;pos < s.size(); pos++)
        {
            char c = s[pos];
            if(c == '[')
            {
                string new_string = decode_helper(++pos, s);
                for(int i = 1; i <= num; i++)
                {
                    word += new_string;
                }
                num = 0;
            }
            else if (c == ']')
            {
                return word;
            }
            else if( isdigit(c))
            {
                num = num*10 + c -'0';
            }
            else
            {
                word += c;
            }

        }
        return word;

    }
};

int main()
{
    string test = "3[a]2[bc]";
    Solution sol;
    string ans = sol.decodeString(test);
    cout << "Ans: " << ans << endl;

}