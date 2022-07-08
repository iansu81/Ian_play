#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
// 解法1:   select
class Solution
{
public:
    // 把find 最大的直接轉成find最小的
    int findKthLargest(vector<int> &nums, int k)
    {
        //找第Ｋ個最大的元素 ＝ 找第（所有元素＋1 -k)個最小的元素 
        return findKthSmallest(nums, 0, nums.size() - 1, nums.size() + 1 - k);
    }
    int findKthSmallest(vector<int> &nums, int left, int right, int k)
    {
        int index = partition(nums, left, right, k);
        //因為index從零開始, 最小的k從1開始, 所以要k-1,當pivot等於k-1的時候就代表左邊的都比他小了,也不用再去排前面的
        if(index == (k - 1)) return nums[index] ;
        // 如果index比k-1大,代表還要繼續往左邊做,但是就不用管右邊的了
        else if(index > (k - 1)) return findKthSmallest(nums, left, index - 1, k);
        // 如果index比k-1小,代表還要繼續往右邊做,但是就不用管左邊的了
        else return findKthSmallest(nums, index+1, right, k);
    }
    int partition(vector<int> &nums, int left, int right, int k)
    {
        // 把最右邊的當作pivot比較, 然後開始做quick select,最後把pivot移動到左邊的都比他小,右邊的都比他大
        int pivot = nums[right];
        int i = left;
        for(int j = left; j <= (right - 1); j++)
        {
            if(pivot >= nums[j])
            {
                swap(nums[i],nums[j]);    
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
};

// 解法2：push到priority queue
// 解法3：quick sort 然後直接pick 元素
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), [] (auto const &left, auto const &right){
            return left < right;
        });
        return nums[nums.size()  - k];
    }
};

    int
    main()
{
    vector<int> test { 3,2,3,1,2,4,5,5,6 };
    // vector<int> test { 3, 2, 3, 1, 2, 4, 5, 5, 6 };

    Solution sol;
//     cout << "INDEX: " << sol.partition(test, 0, (test.size() - 1), 2);
    // cout << sol.findKthSmallest(test, 0, test.size()-1, 5); 
    sol.findKthLargest(test, 4);
}

