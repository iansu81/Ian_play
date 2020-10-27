#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        // 邊界條件：如果numRows == 1, 直接return s
        if(numRows == 1) return s;

        // 建立一個vector, 然後按照各層順序依序填入ex: numRows == 3 : 0 -> 1 -> 2 -> 1 -> 0 -> 1 -> 2
        // 用一個step來記錄要往上還是往下, 到上界就設成1, 下界就設成-1, 最後再iterate 各層合成一個string
        vector<string> storage(numRows, "");
        int step = 1;
        int level = 0;
        for(const auto& e: s )
        {
            storage[level] += e;
            if(level == 0) step = 1;
            if(level == (numRows - 1)) step = -1;
            level += step; 
        }
        string ans = "";
        for(const auto& str : storage)
        {
            ans += str;
        }
        return ans;
    }
};



int main()
{
    string test = "AB";
    Solution sol;
    cout << "Ans: " << sol.convert(test, 1) << endl;

}