#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> ans;
        //紀錄所有letter的順序數字
        for(int i = 0; i < order.size() ; i++ )
        {
            ans[order[i]] = i;
        }

        //把每個位置的char換成數字,再implicitly 轉回char
        for(int i = 0 ; i < words.size(); i++ )
        {
            for(int j = 0 ; j < words[i].size(); j++)
            {
                words[i][j] = ans[words[i][j]];
            }
            //比較現在跟前一個的大小,如果前一個比較大, return false
            if(i > 0 && words[i] < words[i-1]) return false;
        }
        return true;
    }
};



int main(){

    vector<string> test = { "reb", "inci" };
    string test_order =  "tcyklqfhoeapndgbimsujzvxwr";
    Solution sol;
    sol.isAlienSorted(test, test_order);
}