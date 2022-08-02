// 利用兩次的binary search
// 第一次找 Find the smallest i such that A[i] >= target; 如果這時候找到的A[i] != target, 也要返回找不到
// 第二次找 Find the biggest i such that A[i] <= target;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int lo = 0, hi = (nums.size()-1);

        while(lo < hi) {
            int mid = lo + (hi-lo)/2;
            if(nums[mid] >= target) hi = mid;
            else lo = mid+1;
        }
        
        if(nums[lo] != target) {
            return {-1, -1};
        }
        else result.push_back(lo);

        lo = 0;
        hi = nums.size()-1;
        while(lo < hi) {
            int mid = lo + (hi-lo+1)/2;
            if(nums[mid] <= target) lo = mid;
            else hi = mid-1;
        }

        result.push_back(lo);
        return result;
        
    }
};