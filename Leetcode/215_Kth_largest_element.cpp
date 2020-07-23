#include <vector>
#include <queue>
#include <iostream>


using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int index = partition(
        if(in)
        )
    }
    int partition(vector<int> &nums, int left, int right, int k)
    {
        int pivot = nums[right];
        int i = left;
        cout << "AAAAA" << endl;
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

int main()
{
    vector<int> test { 3, 2, 1, 5, 6, 4 };
    // vector<int> test { 3, 2, 3, 1, 2, 4, 5, 5, 6 };

    Solution sol;
    // sol.findKthLargest(test, 2);
    cout << "INDEX: " << sol.partition(test, 0, (test.size() - 1), 2);
}