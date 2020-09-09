#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;



// Key concept: 把vector排成[1,2,3,4,5....]照順序排下去,如果不是照這個順序, 那個位置＋1就是第一個missing的正整數,
// 1 一定在index = 0, 2 一定在index = 1
// 所以一開始我們go thru 所有的element 把他們丟到正確的位置然後就不要動
// ex" [3,4,1,-1] => [1,4,3,,-1] => [1,-1,3,4]
// 接著再跑一次for loop看哪個index數字不是index+1, return 那數字
// 如果跑完 for loop ,就return size + 1

// 這一題bundary check 很重要,要避免nums[nums[i] - 1]不會out of bound
//   所以要避免access 負數跟大於size的數字

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0 && nums[i] < nums.size() && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[nums[i] - 1], nums[i]);
                i--;
            }
        }
        for(int i = 0; i < nums.size(); i++ )
        {
            if(nums[i] != (i + 1) )
            {
                return (i + 1);
            }
        }
        return (nums.size() + 1);
    }
};



int main()
{
    vector<int> test{3, 4, -1, 1};
    Solution sol;
    sol.firstMissingPositive(test);
}


// Example 1 :

//     Input : [ 1, 2, 0 ] Output : 3 Example 2 :

//     Input : [ 3, 4, -1, 1 ] Output : 2 Example 3 :

//     Input : [ 7, 8, 9, 11, 12 ] Output : 1