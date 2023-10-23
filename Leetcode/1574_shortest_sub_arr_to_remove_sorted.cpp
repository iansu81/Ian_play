#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;

 // Sliding window 通常是兩個pointer 往某個方向一起移動, 兩個一起往中間夾比較難做
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {

        if(arr.size() == 0) return 0;
        int left = 0;
        int N = arr.size();
        int right = N -1;
        
        // Left: 從左邊開始數, 第一個峰值(下一個比自己小)
        // Right: 從右邊開始數, 第一個谷(前面那個比自己大)
        // 先把left跟right 找出來
        while((left+1 < N)  && (arr[left+1] >= arr[left]) )  left++;
        if(left == (N-1)) return 0;
        while(right-1 > 0 && (arr[right] >= arr[right-1])) right--;
        
        // Result 最多最多就是把right左邊所有點移除掉或是把left右邊所有點移除掉
        int result = min(N-left-1, right);

        // 接下來2 pointer作法, 左邊從0開始, 右邊從right開始
        // 找出可不可以比result還要少的移除數量
        int i = 0, j = right;
        while(i <= left && j < N) {
             if(arr[i] <= arr[j]) {
        
                result = min(result, j - i - 1);
                i++; 
            }        
            else j++;
        }
        return result;
    }
};






int main() {
    vector<int> test {1,2,3,10,0,7,8,9};

    Solution sol;
    std::cout << sol.findLengthOfShortestSubarray(test) << std::endl;
}
