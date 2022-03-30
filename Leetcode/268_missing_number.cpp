class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 方法1: Sorting之後去遍歷
        // 方法2: 0+1+....+n 答案應該是n*(n+1)/2;
        //   把這個array所有數字加起來拿總和去減掉, 差距就是missing的數字
        int n = nums.size();
        int gaussian_sum = n*(n+1)/2;
        int array_sum = 0;
        for(const auto& e: nums) array_sum += e;
        return gaussian_sum - array_sum;


    }
};