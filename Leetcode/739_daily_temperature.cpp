#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;


// 創建一個嚴格遞減的stack來記錄從最大到最小
// 當遍歷的元素比stack中的元素還要大的時候, 就要把元素pop出來直到比遍歷的元素小或空
// 如果pop完發現是空的, 代表後面沒有元素比正在遍歷的元素還要大, 所以這個元素就應該是0
// 否則就是stack中離這個元素最近的比較大的元素的index-i 
class Solution
{
    public:
        vector<int> dailyTemperature(vector<int>& T)
        {
            stack<pair<int,int>> monodecreasing;
            vector<int> ans(T.size(), -1);
            ans[T.size()-1] = 0;
            monodecreasing.push(make_pair(T.back(), T.size()-1));
            for(int i = T.size()-2; i >= 0; i--)
            {
                while(!monodecreasing.empty() && T[i] >= monodecreasing.top().first) monodecreasing.pop();
                if(!monodecreasing.empty())  ans[i] = monodecreasing.top().second - i;
                else ans[i] = 0;
                monodecreasing.push(make_pair(T[i], i));
    
            }
            return ans;

        }

};


int main()
{
    vector<int> test{73,74,75, 71, 69,72,76,73};
    // [1,1,4,2,1,1,0,0]
    Solution sol;
    vector<int> ans = sol.dailyTemperature(test);
    for(auto& e: ans)
    {
        cout << e << ',';
    }


}