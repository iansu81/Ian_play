#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        // 利用兩個hashmap紀錄遍歷時的資料, 一個紀錄每個數字出現的次數, 一個紀錄每個數字第一次出現時的index i 
        unordered_map<int, int> freq, pos;

        // 紀錄freq最大值, i.d. degree
        int max = 0;

        // 答案, 最短的subarray size
        int result = 0;


        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            // 當遍歷到一個新的數字的時候, 紀錄一下此時的index i
            if(freq[nums[i]] == 1) pos[nums[i]] = i;
            
            // 當有元素的頻率超過max值
            if(freq[nums[i]] > max) {
                max = freq[nums[i]];
                result = ( i - pos[nums[i]] + 1);
            }

            // 如果有freq 相等, 就比較兩個subarray長短
            else if(freq[nums[i]] == max) {
                result = min(result, i - pos[nums[i]] + 1);
            }
        }
        return result;
    }
};



int main () {

    vector<int> test {2,1,1,2,1,3,3,3,1,3,1,3,2};

    Solution sol;
    std::cout << sol.findShortestSubArray(test) << std::endl;
}