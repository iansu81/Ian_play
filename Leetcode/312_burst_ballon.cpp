#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // 根據題目, 要在前後各補兩個1,已方便計算
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> record(n, vector<int>(n,-1));
        return dp(0, n-1, nums, record);   
    }

    // 這個dp是在遍歷left到right中間(不包含left, right),找出最大的組合
    int dp(int left, int right, vector<int>& nums, vector<vector<int>>& record)
    {
        // 如果left+1 == right, 代表兩個中間沒有任何元素, 直接return 0
        if((left+1) == right) return 0;
    
        // 之前就已經尋訪過, 所以直接return 值
        if( record[left][right] != -1) return record[left][right];

        // 接下來遍歷left 到right中間ㄉ元素, 利用recursive 方法去找最大值
        for(int i = (left + 1); i < right; i++)
        {
            record[left][right] = max(record[left][right], nums[left]*nums[i]*nums[right]
                            + dp(left, i, nums, record) + dp(i, right, nums, record) );
        }
        return record[left][right];

    }
};


int main()
{
    vector<int> test{3,1,5,8};
    Solution sol;
    cout << "Ans: " << sol.maxCoins(test) << endl;

}