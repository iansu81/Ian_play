class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector< vector<int> > result;
            // 一定要先排序, 因為題目說答案不能有重複的set, 排序後會把相同的數字放在一起比較好filter
            sort(nums.begin(), nums.end());
            // 從最小的數開始做, left設成這個數的下一個, right從後面開始算
            for(int i = 0; i < nums.size(); i++){
                int left = i+1;
                int right = nums.size() - 1;
                while(left < right){
                    int sum = nums[left] + nums[right];
                    // 當後面兩個數比-nums[i]小, 代表後面兩個數的值要變大. 因為array已經是排序過的,
                    // 所以增加left index
                    if(sum < -nums[i]){
                        left++;
                    }
                    // 當後面兩個數比-nums[i]大, 代表後面兩個數的值要變小. 因為array已經是排序過的,
                    // 所以減少right index
                    else if(sum > -nums[i]){
                        right--;
                    }
                    else{
                        vector<int> record(3,0);
                        record[0] = nums[i];
                        record[1] = nums[left];
                        record[2] = nums[right];
                        result.push_back(record);
                        
                        // 這兩個while是用來解決原本array裡面重複的數字
                        while(left < right && nums[left] == record[1]){
                            left++;
                        }
                        while(left < right && nums[right] == record[2]){
                            right--;
                        }                    
                    
                    
                    }

                }
                // 如果有重複的數字, 就不用在找一遍
                while(i < (nums.size() - 1) && nums[i] == nums[i+1]){
                    i++;
                }
            }
            return result;
            
        }
};