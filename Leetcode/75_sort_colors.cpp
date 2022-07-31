#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {

        // low: 用來記錄1的最前面的index
        // high: 用來記錄1的最後面的index
        // mid: 拿來遍歷的index 
        int low = 0, mid = 0, high = (nums.size()-1);
        while(mid <= high) {
    
            switch(nums[mid]) {

                // 當mid碰到一個0的時候, 就把1最前面的index跟mid對調
                // 因為low是拿來記錄最前面的1的, 所以這邊mid++之後
                // low也要++
                case 0:
                    swap(nums[low], nums[mid]);
                    low++;
                    mid++;
                    break;

                // 碰到1就去找下一個1即可
                case 1:
                    mid++;
                    break;

                // 遇到2的話要換到最後面去, 但是因為不知道從後面換過來的是什麼數字
                // 所以下一個iteration還要再確定一次換過來的數字, 所以不用mid++
                case 2:
                    swap(nums[mid], nums[high]);
                    high--;
                    break;
            }
        }
        
    }
};

int main() {
    vector<int> test{1,2,0};
    Solution sol;
    sol.sortColors(test);
    for(const auto& e:test) {
        std::cout << e << ',';
    }
    std::cout << std::endl;


}
