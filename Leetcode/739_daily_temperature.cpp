#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution
{
    public:
        vector<int> dailyTemperature(vector<int>& T)
        {
            stack<pair<int,int>> monodecreasing;
            vector<int> ans;
            ans.push_back(0);
            monodecreasing.push(make_pair(T.back(), T.size()-1));
            for(int i = T.size()-2; i >= 0; i--)
            {
                if(T[i] < monodecreasing.top().first)
                {
                    ans.push_back(monodecreasing.top().second - i);
                    monodecreasing.push(make_pair(T[i], i));
                }
                else{
                    while(T[i] >= monodecreasing.top().first)
                    {
                        monodecreasing.pop();
                    }
                    if(!monodecreasing.empty())
                    {
                        ans.push_back(monodecreasing.top().second - i);
                    }
                    else
                    {
                        ans.push_back(0);
                    }
                    monodecreasing.push(make_pair(T[i], i));
                }
            }
            reverse(ans.begin(), ans.end());
            return ans;

        }

}


int main()
{
    vector<int> test{73,74,75, 71, 69,72,76,73};
    // [1,1,4,2,1,1,0,0]
    Solution sol;

    cout << endl;


}