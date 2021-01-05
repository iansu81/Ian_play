class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxAll = nums[0];
        int maxSum = nums[0];
        for(int i = 1 ; i < nums.size(); i++ ){
            maxSum = (maxSum+nums[i] > nums[i]) ? maxSum+nums[i] : nums[i];
            maxAll = max(maxAll, maxSum);
        }
        return maxAll;
    }
};