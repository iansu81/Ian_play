#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



// 利用Sliding window來掃array, 每次如果前進一個r,找到一個新subarray的時候, 必須要加上r-l;
// 假設subarray裡面有{10, 2, 3}, 掃到3的時候, 會多一個{3}, {2, 3}, {10, 2, 3}總共要加上3個

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int l = 0, r = 0;
        int product = 1;
        if(k == 0) return 0;
        while(r < nums.size()) {
            product *= nums[r++];
            
            //一定要加上l < r 這個check, 否則會有 l > r的情況, 造成count 變成負的 
            while(product >= k && l < r) {
                product /= nums[l++];
            }

            count += (r - l);
        }
        return count;

    }
};

int main() {
    Solution sol;
    vector<int> test {1, 1, 1};
    cout << sol.numSubarrayProductLessThanK( test, 1) << endl;


}