#include <vector>
#include <queue>
#include <iostream>


using namespace std;

class Solution
{
public:
    // int findKthLargest(vector<int> &nums, int k)
    // {
    //     int index = partition()
    // }
    int partition(vector<int> &nums, int left, int right, int k)
    {
        int pivot = nums[right];
        int i = left - 1;
        for(int j = left; j < (right - 1); j++)
        {
            if(nums[right] > nums[j])
            {
                swap(nums[i],nums[j]);    
                i++;
            }
        }
        swap(nums[i], pivot)
        return i;
    }
};

int main()
{
    vector<int> test { 3, 2, 1, 5, 6, 4 };
    // vector<int> test { 3, 2, 3, 1, 2, 4, 5, 5, 6 };

    Solution sol;
    // sol.findKthLargest(test, 2);
}