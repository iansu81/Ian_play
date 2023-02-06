


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> record;
        int current_sum = 0;
        int start = 0;
        backtrack(candidates, target, current_sum, start, record, result);
        return result;
    }
    
    void backtrack(vector<int>& candidates, int target, int current_sum, int start, vector<int>& record, vector<vector<int>>& result){
            
            
            if(current_sum == target) {
                result.push_back(record);
                return;
            }
            // 當sum>target, 就不應該繼續找下去
            if(current_sum > target) return;


            // 因為是找子集不是找排列, 所以這邊要用start而不是0
            for(int i = start; i < candidates.size(); i++){
                current_sum += candidates[i];
                record.push_back(candidates[i]);

                // 因為元素可以重複使用, 所以下一個round一樣從i找
                backtrack(candidates, target, current_sum, i, record, result);
                
                current_sum -= candidates[i];
                record.pop_back();
                
            }
        
    }
};