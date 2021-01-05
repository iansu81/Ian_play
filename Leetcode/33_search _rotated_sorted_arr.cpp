
// 方法1: 找到array裡面哪邊是轉折點, 然後把target跟nums[0]比較, 看是要找哪一個part;
// 方法2:

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while( left <= right )
        {
            int mid = left + (right - left) / 2;
            if( target == nums[mid] )
            {
                return mid;
            }

            // 兩種情況:
            // case1: mid在轉折點之前
            else if( nums[mid] >= nums[left])
            {
                // left 到mid是嚴格遞增的array, 如果確認在mid左邊的話,就直接往左邊做binary search
                if( target >= nums[left] && target < nums[mid])
                {
                    right = mid - 1;
                }
                // 往右邊做binary search
                else{
                    left = mid + 1;
                }
            }

            // case2: mid在轉折點之後
            else{
                // mid 到right是嚴格遞增的array, 如果確認在mid右邊的話,就直接往右邊做binary search
                if( target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                // 往左邊做binary search
                else
                {
                    right = mid - 1;    
                }
            }
            
        }
        return -1;
        
        
    }
};