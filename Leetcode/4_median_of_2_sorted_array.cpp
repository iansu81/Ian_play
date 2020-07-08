#include <vector>
#include <iostream>
#include <climits>

using namespace std;

//把兩個vector各切成左右兩邊median是兩個vector左邊最大的 或 左邊最大的跟右邊最小的平均
class Solution
{
    public:
        double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
        {
            int n1 = nums1.size();
            int n2 = nums2.size();
            //當n1 size > n2 size的時候把他們反過來做,對小的做binary search 比較快
            if(n1 > n2)
            {
                return findMedianSortedArrays(nums2, nums1);
            }
            //  如果2個vector加起來是5個,中位數是第三個,如果加起來是6個, 中位數是第三個跟第四個平均, 所以把兩個加起來＋1比較好找中位數
            int k = (n1+n2+1)/2;

            //nums1最少可能取0個最多可能取n1個     
            int left = 0;
            int right = n1;

            int max_n1_left, min_n1_right, max_n2_left, min_n2_right;
            while( left <= right )
            {
                //n1左邊數目
                int n1_num = left + (right - left) / 2;
                int n2_num = k - n1_num;
                //當n1取0個的時候, 代表n1左邊沒東西, 用一個極小的value去代表
                max_n1_left = (n1_num == 0) ? INT_MIN : nums1[n1_num - 1];
                //當n1全取的時候, 代表n1右邊沒東西, 用一個極大的value去代表
                min_n1_right = (n1_num == n1 )? INT_MAX : nums1[n1_num];
                max_n2_left = (n2_num == 0) ? INT_MIN : nums2[n2_num - 1];
                min_n2_right = (n2_num == n2) ? INT_MAX : nums2[n2_num];
                
                // 當n1 左邊最大大於n2右邊最小的時候, 代表n1取太多, 要少取一點
                if ( max_n1_left > min_n2_right ) right = n1_num - 1;
                // 當n2 左邊最大大於n1右邊的時候,代表 n1要多取一點
                else if( max_n2_left > min_n1_right ) left = n1_num + 1;
                // 當n1, n2 左邊全部小於n1,n2右邊的時候, 就是我們要的 
                else break;
            }
            //當兩個數目加起來是偶數, 必須要取平均
            if (((n1 + n2) % 2) == 0)
            {
                int median_left = max(max_n1_left, max_n2_left);
                int median_right = min(min_n1_right, min_n2_right);
                return double(median_left + median_right) / 2.0;
            }
            else
            {
                return max(max_n1_left, max_n2_left);
            }
        }
};

int main(){

    Solution sol;
    vector<int> test2{1, 2};
    vector<int> test1{3, 4};
    cout << "ANS: " << sol.findMedianSortedArrays(test1, test2) << endl;
}