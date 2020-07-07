


class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int ans = 0;
        //Go thru all the element, 只有當元素不等於val的時候把它copy到nums裡面
        for(int i = 0 ; i < nums.size(); i++ )
        {
            if(nums[i] != val)
            {
                nums[ans] = nums[i];
                ans++;
            }

        }
        return ans;
    }
};