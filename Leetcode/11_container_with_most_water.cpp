


// 用兩個變數一直去track左邊最跟右邊最高,取min之後＊兩個的差距就是container的水量
// 每次移動都移動比較低的那個, 因為移動比較高的不會使water變多
 



class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxVolume = 0;
        int left = 0;
        int right = height.size() - 1;
        while( left < right ){
            maxVolume = max( maxVolume, min( height[left], height[right] ) * (right - left) );
            if( height[ left ] < height[right] ){
                
                left++;
            }
            else{
                right--;
            }
        }
        return maxVolume;  
                
    }
};