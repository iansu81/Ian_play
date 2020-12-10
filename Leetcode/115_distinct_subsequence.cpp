#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        // dp[i][j] 意思是在s中取到第j-1個char的時候, 跟t取到第i-1個元素的時候, 有多少組解
        vector<vector<long>> dp(t.size()+1 , vector<long>(s.size()+1, 0));
        // 當t取0個元素時, s都只有一組解, 就是完全不取
        fill(dp[0].begin(), dp[0].end(), 1);
        for(int i = 1; i <= t.size(); ++i)
        {
            for(int j = 1; j <= s.size(); ++j)
            {
                // 當s跟t的char不相等的時候, 就只要用s的前面一個元素, 不用加任何東西, 代表我們現在取的s的char沒有任何作用
                // 但是當s比較的char,跟t比較的char相等的時候, 就要再加上沒有取這個比較的char時候的解
                // ex: t == rab, s == rabbx
                // 當i==3, s ==3
                // dp[3][3] = dp[2][2](t[0~1] == s[0~1, 再加上現在s跟t的char都一樣]) + dp[3][2](0)
                // i==3, t==4
                // dp[3][4] = dp[2][3] + sp[3][3]
                // i=3, t == 5
                // dp[3][5] = dp[3][4](x完全沒有任何作用, 只是繼承前面的數量)

                if(t[i-1] == s[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }
            
                else
                {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[t.size()][s.size()];
    }
};


int main()
{

    string test_s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
    string test_t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
    Solution sol;
    cout << "Ans: " << sol.numDistinct(test_s, test_t);
}