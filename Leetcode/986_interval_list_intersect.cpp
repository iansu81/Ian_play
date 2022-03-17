
#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        // 利用兩個index 分別指向兩個list
        // 有intersection的情況是在兩個start time比較晚的小於等於兩個end time 比較早的 (等於是題目說的)
        // 這時候就push 進去result裡面
        // 接下來比較哪一個end 時間比較早，把end time比較早的index+1, 這樣才能確定另一個list中現在正在iterate的item有沒有跟這一個list的下一個 item有interection
        int i = 0;
        int j = 0;
        vector<vector<int>> result;
        while(i < firstList.size() && j < secondList.size() ) {

            int intersection_low = max(firstList[i][0], secondList[j][0]);
            int intersection_high = min(firstList[i][1], secondList[j][1]);
            if( intersection_low <= intersection_high) 
            {
                result.push_back({intersection_low, intersection_high});
            }
            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;

        }
        return result;

    }
};