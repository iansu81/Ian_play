/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;


// class Solution {
// public:
//     // int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
//     // }
//     int binary_search(vector<int> vec)
//     {
//         int left = 0;
//         int right = vec.size() - 1;
//         while(left <= right)
//         {
//             int mid = (left+right)/2;
//             if( vec[mid] == 1 && vec[mid-1] == 0)
//             {
//                 return mid;
//             }
//             else if(vec[mid] == 1)
//             {
//                 right = mid - 1;
//             }
//             else{
//                 left = mid + 1;
//             }
//         }
//         return -1;

//     }
// };


int main()
{
    vector<int> test{3,4,5,2,1};
    // Solution sol;

    // sort(test.begin(), test.end(),  [](const int& a, const int& b)->bool {
    //         return a > b;
    //     });

    for(auto e: test)
    {
        cout << e << ",";
    }
    // cout << "Ans: " << sol.binary_search(test);


}