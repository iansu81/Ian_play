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
        if(nums.size() < 3) return 0;
        int ans = 0;
        // 把整個vector從小排到大
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i ++)
        {
            // C 是要搜尋的裡面最大的
            // B 是要搜尋的裡面第二大的
            // A 是搜尋範圍裏面最小的 
            int c = nums.size() - 1 - i;
            int a = 0;
            int b = c - 1;
            // Fix C 然後change A 跟B
            while(a < b)
            {
                // 1. 當nums[A] + nums[B] > nums[C]的時候, 代表 A~B中的所有元素都是可以的, 所以紀錄下來然後把B往下調一個
                // 2.  當兩邊和<第三邊的時候, 將A的值加上去, 直到找到or搜尋完
                if(nums[a] + nums[b] > nums[c])
                {
                    ans += (b-a);
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
    vector<int> test { 2,2,3,4 };
    Solution sol;
    int ans = sol.triangleNumber(test);
    cout << "Ans: " << ans << endl;
    
}