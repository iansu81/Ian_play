class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector< vector<int> > result;
            sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.size(); i++){
                int left = i+1;
                int right = nums.size() - 1;
                while(left < right){
                    int sum = nums[left] + nums[right];
                    if(sum < -nums[i]){
                        left++;
                    }
                    else if(sum > -nums[i]){
                        right--;
                    }
                    else{
                        vector<int> record(3,0);
                        record[0] = nums[i];
                        record[1] = nums[left];
                        record[2] = nums[right];
                        result.push_back(record);
                        
                        while(left < right && nums[left] == record[1]){
                            left++;
                        }
                        while(left < right && nums[right] == record[2]){
                            right--;
                        }                    
                    
                    
                    }

                }
                while(i < (nums.size() - 1) && nums[i] == nums[i+1]){
                    // cout << "Skip" << i << endl;
                    i++;
                }
            }
            return result;
            
        }
};