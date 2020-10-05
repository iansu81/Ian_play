#include <iostream>
#include <vector>
#include <string>

using namespace std;


// keypoint: index = n位置的數字-（n+1） 就是前面有幾個missing positive number
// ex: [2,3,4,100]; 當index = 2 => 4-(2+1) = 1 => 代表前面有一個missing positive number ＝> 1
// 另外當K = 10; 這個數字在4~100中間, 我們必須要找到這個數字在哪個數字右邊, 然後再用那個數字的index + K 即為答案;
// 我們知道這個數字在4右邊,4左邊包含自己有2,3,4三個positive number了, 所以再加上missing 的10個 ＝ 13, 不用管左邊的positive number是多少


class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int l = 0;
        int r = arr.size();
        while(l < r)
        {
            int mid = l + (r-l)/2;
            // arr[mid] - (mid+1) > k 代表那個missing the positive 就在這mid前面所以要縮小範圍, =k代表就在mid前面最大的missing positive number
            if( (arr[mid] - (mid+1)) >= k){
                r = mid;
            }
            else {
                l = mid+1;
            }
        }

        return l+k;

    }
};


int main()
{
    vector<int> test { 2, 3, 4, 7, 11 };
    Solution sol;
    cout << "ANS: " << sol.findKthPositive(test, 5) << endl;
    // ans == 9

}