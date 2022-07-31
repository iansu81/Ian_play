#include <vector>
#include <iostream>
using namespace std;


// 概念: 最後的結果一定是所有負的elements都在左邊, 正的elements都在右邊
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for(int i = 0 ; i < asteroids.size(); i++) {

            // 如果新的elemet是正的, 或是result裡面沒有任何東西, 或是result的最右邊元素已經是負的了,
            // 就只要直接把element push進去就好
            if(asteroids[i] > 0 || result.empty() || result.back() < 0) {
                result.push_back(asteroids[i]);
            }

            // 如果當新的element是負的 ,result最後一個元素又是正的, 這時候就必定發生碰撞, 
            // 同時也要考慮兩種情況 1. 新的元素size比較大, 這時候除了把result最後面的元素remove掉, 還要再跟更前面的比較
            //  2. 新的元素跟result最後面的元素一樣大, 這時候就只要把最後面的元素remove掉即可
            else if( result.back() <= (-asteroids[i]) ) {
                if( result.back() < (-asteroids[i]) ) i--;
                result.pop_back();
            }
            // 如果新元素是負的又比result最後面的元素size還要小, 這時候直接忽略新元素即可
        }
        return result;
    }
};

int main() {

    vector<int> test{8, -8};
    Solution sol;
    vector<int> ans = sol.asteroidCollision(test);
    for(const auto& a : ans){
        std::cout << a << ',';
    }


}