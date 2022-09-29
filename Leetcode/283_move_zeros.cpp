#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0;
        while( r < nums.size()) {
            if(nums[r] != 0) {
                swap(nums[l], nums[r]);
                l++;
            }
            r++;
        }

    }
};



int main() {
    vector<int> test{0,1,0,3,12};
    Solution sol;
    sol.moveZeroes(test);
    for(const auto& x:test) {
        std::cout << x << ',';
    }
    std::cout << endl;


}