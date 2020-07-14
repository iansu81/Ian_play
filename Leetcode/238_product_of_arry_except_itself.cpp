#include <vector>
#include <iostream>

using namespace std;



class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
        vector<int> result;

        //紀錄在所有在index i左邊元素的乘積
        for(int i = 1; i < nums.size(); ++i)
        {
            left[i] = left[i-1] * nums[i-1];
        }
        //紀錄在所有在index i右邊元素的乘積
        for(int i = nums.size() - 2; i >= 0; --i )
        {
            right[i] = right[i+1] * nums[i+1] ;
        }
        //所有左邊的乘積＊所有右邊的乘積即為答案
        for(int i = 0; i < nums.size(); ++i)
        {
            result.push_back(left[i]*right[i]);
        }
        return result;

    }
};


int main(){
    vector<int> test { 1, 2, 3, 4 };
    Solution sol;
    vector<int> result = sol.productExceptSelf(test);
    for(int i =0 ; i < result.size(); i++){
        cout << result[i] << endl;
    }
}