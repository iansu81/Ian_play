class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0){
            return 0;
        }
        int ans = 0;
        int left = 0;
        int right = height.size() - 1;
        int max_left = height[left];
        int max_right = height[right];
        while(left < right){
            if(max_left < max_right){
                ans += max_left - height[left];
                left ++;
                max_left = max( max_left, height[left]);
            }
            else{
                ans += max_right - height[right];
                right--;
                max_right = max(max_right, height[right]);
            }
        }
        return ans;
        
    }
};