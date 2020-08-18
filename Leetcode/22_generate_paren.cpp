#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    void dfs(int l, int r, string s, vector<string> result)
    {   
        if(l == 0 && r==0)
        {
            result.push_back(s);
            return;
        }
        if( r > 0) dfs(l, r-1, s)
        if( l > 0)

    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        dfs(n, 0,"", ans);
        return ans;
    }

};

int main()
{

    Solution sol;
    vector<string> result = sol.generateParenthesis(3);
    for(int i = 0 ; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }


}