#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        if(matrix.size() == 0)
        {
            return result;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        //記錄所有的element才知道要不要繼續遍歷
        int total_element = m*n;
        // 紀錄已經訪問了幾個element
        int visited_item = 0;
        // 持續記錄所有的boundary
        int left = 0;
        int top = 0 ;
        int right = n-1;
        int bottom = m-1;
        while( visited_item < total_element)
        {
            // 從左到右訪問上面的列
            for(int i = left; i <= right && visited_item < total_element; i++)
            {
                result.push_back(matrix[top][i]);
                visited_item++;
            }
            // 因為最右上角的element已經被前面的紀錄了所以不用再紀錄,從top+1開始往下遍歷
            top++;
            for(int i = top; i <= bottom && visited_item < total_element; i++ )
            {
                result.push_back(matrix[i][right]);
                visited_item++;
            }
            // 因為最右下角的element已經被前面的紀錄了所以不用再紀錄, right - 1開始往左遍歷
            right--;
            for(int i = right; i >= left && visited_item < total_element; i--)
            {
                result.push_back(matrix[bottom][i]);
                visited_item++;
            }
            // 避免訪問最左下角的element
            bottom--;
            for (int i = bottom; i >= top && visited_item < total_element; i--)
            {
                result.push_back(matrix[i][left]);
                visited_item++;
            }
            left++;
        
        }
        return result;
    }
};



int main()
{
    vector<vector<int>> test{
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }
    };
    Solution sol;
    vector<int> ans = sol.spiralOrder(test);
    for(int i = 0; i < ans.size();i++)
    {
        cout << ans[i] << ',';
    }
}