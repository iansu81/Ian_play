#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>


using namespace std;



class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        int size = flowerbed.size();
        for(int i = 0; i < size; i++) {

            // 當自己是0, 且前面(或是沒有前面)也是0, 且後面(或是沒有後面)也是0, 才可以種花
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == (size-1) || flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                n--;
                if(n == 0) return true;
            } 

        }
        return false;
        
    }
};

int main() {
    vector<int> test{1,0,0,0,1};

    Solution sol;
    int ans = sol.canPlaceFlowers(test, 2);
    std::cout << "Result: " << ans ;
    std::cout << endl;
}


