#include <vector>
#include <iostream>
using namespace std;


// 因為題目說 1 ≤ a[i] ≤ n (n = size of array)
// 所以所有的元素, 都可以被拿來當array的index,
// 當我們遍歷元素的時候, 就把元素當作index, 第一次遇到的時候把nums[abs(元素)-1]都變成負的, 
// 當下一次又遇到duplicate的元素時, nums[abs(元素)-1]如果是負的, 我們就知道元素重複了 
// 取abs的原因是因為可能這個數已經變成負的了, 不取會out of range.

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> ans;
        for(auto val: nums)
        {
            if(nums[abs(val) - 1] < 0) ans.push_back(abs(val));
            nums[abs(val) - 1] *= -1;
        }
        return ans;
    }
};


int main()
{
    vector<int> test {4,3,2,7,8,2,3,1};
    Solution sol;
    vector<int> ans = sol.findDuplicates(test);
    for(auto e: ans)
    {
        cout << e << endl;
    }

}