#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
// 解法1: quick select
// 參考215只是最後return vector而不是index
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K){
        return K_closeest_with_index(points, 0, points.size() - 1, K);
    }
    vector<vector<int>> K_closeest_with_index(vector<vector<int>> &points, int left, int right, int K)
    {
        int index = partition(points, left, right, K);
        if (index == (K - 1)){
            //把前面Ｋ個元素提取出來
            vector<vector<int>>::const_iterator first = points.begin();
            vector<vector<int>>::const_iterator last = points.begin()+K;
            vector<vector<int>> newVec(first, last);
            return newVec;

        }
        else if (index >= K) return K_closeest_with_index(points, left, index - 1, K);
        else return K_closeest_with_index(points, index+1, right, K);
    }
        
    int partition(vector<vector<int>> &points, int left, int right, int K)
    {
        int pivot = cal_distance(points[right]);
        int i = left;
        for(int j = left; j < right; j++)
        {
            if(pivot >= cal_distance(points[j]) ){
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
    // vector<vector<int>> test{{ 3, 3 }, { 5, -1 }, { -2, 4 }};
    vector<vector<int>> test{{1, 3}, {-2, 2}, {2, -2}};

    Solution sol;
    cout << "Index:" <<sol.partition(test, 0, test.size()-1, 1) << endl;
    for (int i = 0; i < test.size(); i++)
    {
        for (int j = 0; j < test[i].size(); j++)
        {
            cout << test[i][j] << ',';
        }
        cout << endl;
    }
    cout << "Index:" << sol.partition(test, 1, test.size() - 1, 1) << endl;

    // vector<vector<int>> ans = ;
    // cout << sol.findKthSmallest(test, 0, test.size()-1, 5);
    // vector<vector<int>> ans = sol.kClosest(test, 2);
    for (int i = 0; i < test.size(); i++)
    {
        for (int j = 0; j < test[i].size(); j++)
        {
            cout << test[i][j] << ',';
        }
        cout << endl;
    }
}

 