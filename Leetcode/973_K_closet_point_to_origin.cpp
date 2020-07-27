#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
// 解法1: quick select
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K){
        return K_closeest_with_index(points, 0, points.size() - 1, K);
    }
    vector<vector<int>> K_closeest_with_index(vector<vector<int>> &points, int left, int right, int K)
    {
        int index = partition(points, 0, right, K);
        if (index == K){
            return points[index];

        }
        else if (index > K) return K_closeest_with_index(points, left, index - 1, K);
        else return K_closeest_with_index(points, index+1, right, K);
    }
        
    int partition(vector<vector<int>> &points, int left, int right, int K)
    {
        int pivot = cal_distance(points[right]);
        int i = left;
        for(int j = 0; j < right; j++)
        {
            if(pivot > cal_distance[j]){
                swap(points[i], points[j]);
                i++;
            }
        }
        swap(points[right], points[i]);
        return i;
    }
    int cal_distance(vector<int> point)
    {
        return point[0]*point[0] + point[1]*point[1];
    }
};

int main()
{
    vector<int> test{3, 2, 3, 1, 2, 4, 5, 5, 6};
    // vector<int> test { 3, 2, 3, 1, 2, 4, 5, 5, 6 };

    Solution sol;
    //     cout << "INDEX: " << sol.partition(test, 0, (test.size() - 1), 2);
    // cout << sol.findKthSmallest(test, 0, test.size()-1, 5);
    sol.findKthLargest(test, 4);
}
