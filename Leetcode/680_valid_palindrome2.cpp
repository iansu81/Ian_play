

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


//Palindrome 作法： 從最外圍用兩個pointer比較, 每次l++, r--往中間靠近
// 這一題比較特別是因為允許我們拿掉一個元素, 所以當第一次遇到不合的元素,就往右/往左位移一個元素,確認剩下的是不是palindrome.
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        while( l < r )
        {
            if( s[l] != s[r] ) return (is_valid(s, l+1, r) || is_valid(s, l, r-1));
            l++;
            r--;
        }
        return true;
    }
    bool is_valid(string s, int l, int r)
    {

        while(l < r)
        {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
};


int main()
{
    string test = "abca";
    Solution sol;
    cout << "Ans: " << sol.validPalindrome(test) << endl;

}