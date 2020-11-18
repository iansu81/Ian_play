
#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        // dp[i] 代表取了i個char
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            // 第一個if專門用來確認只有一是個元素的狀態, 如果目前的s[i] >= 1的話, 
            // 代表取到i+1個元素的時候, 組合都valid, 這時候就可以把取i個元素時候的組合加上去
            // 如果當s[i] == 0的時候, 因為不能單獨轉成一個英文字母, 這時候就只能靠0前面的那個數字,s[i-1]+s[i]這樣看是不是valid
            if(s[i] >= '1') dp[i+1] += dp[i];
            // 從第二個字母開始除了看本身的字母是不是valid之外, 還可以同時看s[i-1]+s[i]是不是valid,如果是valid, 就可以把這個組合, 再加上去
            if(i >= 1)
            {
                string two_integer = s.substr(i-1, 2);
                if( two_integer >= "10" && two_integer <= "26") dp[i+1] += dp[i-1];
            }
        }
        return dp[n];  
    }
};





int main()
{
    Solution sol;
    string test = "12";
    cout << "Ans: " << sol.numDecodings(test) << endl;

}