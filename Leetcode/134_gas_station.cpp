#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;


// 邏輯: 利用兩個變數, 一個total_gas用來計算到底有沒有辦法走一圈，
// 另一個current_gas用來記錄從哪個點開始走最好，當current_gas < 0，
// 代表從這個點之前出發會沒辦法走到下一個點，題目又說如果有解會是唯一解，
// 所以碰到current_gas < 0的時候，就重設答案的index為下一個點並且重設current_gas=0，
// 最後確認total_gas如果大於等於0代表有解就回傳result。
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int current_gas = 0;
        int total_gas = 0;
        int result = 0;
        for(int i = 0; i < gas.size(); i++) {
            current_gas += (gas[i] - cost[i]);
            total_gas += (gas[i] - cost[i]);
            if(current_gas < 0) {
                result = i+1;
                current_gas = 0;
            }
        }

        return (total_gas >= 0) ? result : -1;
        
    }
};

