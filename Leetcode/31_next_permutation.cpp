#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int i = nums.size() - 2;
        // 如果都是降序的話,代表從最後面到這個數字為止,已經是排列組合裡面最大的了
        // ex: 3,2,1       5,3,2
        // i從倒數第二個元素開始找,因為這樣才可以比是升序還是降序
        // 所以第一個任務是找到第一個升序,i就是這個升序的位置
        // ex: 8736421, i要指向 3 
        // 如果i是-1,代表已經沒有比這個數字更大的permutation了
        // 所以直接reverse整個vector
        while( i >= 0 && nums[i+1] <= nums[i]) i--;
        cout << "I: " << i << endl;
        // 接下來從後往前,找出第一個比這個數還大的數字
        // ex: 8736421, j指向 4 => 8746321
        int j = nums.size() - 1;
        if(i >= 0)
        {
            while( nums[j] <= nums[i]) j--;
            cout << "J: " << j << endl;
            swap(nums[i], nums[j]);
        }

        // 36421已經是3XXXX裡面最大的了＝ > 下一個要找4XXXX裡面最小的,
        //但是6321是降序裡面最大的,要把它反過來才會是最小的
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main()
{
    vector<int> test = { 1,
                         2,
                         3 };

    Solution sol;
    sol.nextPermutation(test);
    for(int i = 0 ; i < test.size(); i++)
    {
        cout << test[i] << ", ";
    }

}


