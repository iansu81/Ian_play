// Note: if a < b < c 只要確定 a+b > c
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i ++)
        {
            int c = nums.size() - 1 - i;
            int a = i;
            int b = c - 1;
            while(a < b)
            {
                if(nums[a] + nums[b] > nums[c])
                {
                    ans++;
                    b--;
                }
                else a++;
            }
        }
        return ans;
    }
};



int main()
{
    vector<int> test { 2, 2, 3, 4 };
    Solution sol;
    int ans = sol.triangleNumber(test);
    cout << "Ans: " << ans << endl;
    
}