#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;



// 算法: binary search
// key: 如果divisor比nums最大的數還要大, 不論多大, 答案都是2N, N=size of nums
// 所以做比nums最大的數還要大的部份就是白做

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element (nums.begin(), nums.end());
        while( left < right )
        {
            int mid = left + (right - left) / 2;
            int val = 0;
            // 計算除完之後所有的sum, 分成兩種情況, 如果剛好可以整除, 就回傳商
            // 如果不能整除, 就回傳商＋1
            for(auto & ele: nums)
            {
                int q = ((ele % mid) == 0) ? ele/mid : (int(ele/mid)+1); 
                val += q;
            }
            
            if( val <= threshold ) right = mid;
            else left = mid+1;
        }
        return left;
        
    }
};

int main()
{
    vector<int> test{1,2,5,9};
    Solution sol;
    cout << "Ans: " << sol.smallestDivisor(test, 6);

    
}