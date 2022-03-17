#include <iostream>
#include <vector>
#include <string>


class SparseVector {
public:
    // 將constructor 的vector裡面存的數字存到hash map裡面, 0就可以忽略
    SparseVector(vector<int> &nums) {
        for(int i = 0 ; i < nums.size(); i++) {
            if(nums[i] != 0) record[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    // Iterate 整個已經儲存的record中有的值(skip掉0)來計算內積
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        for(auto& [key, val]: record) {
            ans+= (record[key]*vec.record[key]);
        }
        return ans;
    }
    unordered_map<int, int> record;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);