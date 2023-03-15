class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        // 一定要先sort
        sort(nums.begin(), nums.end());

        // diff 紀錄的是target 跟3 sum之間的差距
        // 注意這邊紀錄的是實際值, 不能記錄絕對值, 紀錄絕對值最後return不出正確結果
        int diff = INT_MAX;

        // 跟3sum一樣概念, 只是搜尋條件必須要改
        for(int i = 0; i < (nums.size()-1); i++){
            
            int lo = i + 1;
            int hi = nums.size()-1;
            while(lo < hi ){
    
                int sum = nums[i] + nums[lo] + nums[hi];
                if(abs(target - sum) < abs(diff)) {
                    diff = target-sum;

                    // 如果找到跟target 一樣的, 就直接return
                    if(diff == 0) return target;
                }
                else if(sum > target) hi--;

                else if(sum < target) lo++;
                
            }
        }
        return target-diff;

        
    }
};