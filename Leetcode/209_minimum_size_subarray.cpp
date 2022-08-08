#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


// 利用sliding window來掃array
// 先移動右邊的pointer, 當確定sum of subarray超過target之後,再移動左邊的pointer,去找出有沒有更好的解

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, sum = 0,len = INT_MAX;
        while(r < nums.size()) {
            sum += nums[r++];
            while( sum >= target) {
                len = min(r-l, len);   
                sum -= nums[l++];
            }
        }
        return  (len == INT_MAX) ? 0 : len;
    }
};

int main() {

    Solution sol;
    vector<int> test {2,3,1,2,4,3};
    cout << sol.minSubArrayLen(7, test) << endl;
}

