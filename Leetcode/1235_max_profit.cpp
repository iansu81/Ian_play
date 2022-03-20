#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    
    // 第一步: 根據end time 去排列所有的job
    vector<vector<int>> jobs;
    for(int i = 0; i < startTime.size(); i++ ) {
        jobs.push_back({endTime[i], startTime[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end());
    
    // 第二步，iterate 所有的job，每次都嘗試去找在dp裡面，結束時間比我正要iterate的starttime還要早的
    // 把那個profit + 現在iterate 的profit 加在一起跟dp裡面最後面也應該是最大的比較，如果比較大，就把新的這個放到DP裡面
    // 因為我們iterate job的時候這個job已經是排列過的，所以時間應該是越來越大的
    // dp[time(結束時間)] = profit
    map<int, int> dp = {{0, 0}};
    for (auto& job : jobs) {
        int cur = prev(dp.upper_bound(job[1]))->second + job[2];
        if (cur > dp.rbegin()->second)
            dp[job[0]] = cur;
    }

    // 最後回傳dp最後面的profit
    return dp.rbegin()->second;


}



int main()
{
    vector<int> start{ 1,2,3,3 };
    vector<int> end{ 3,4,5,6 };
    vector<int> profit{ 50,10,40,70 };
    jobScheduling(start, end, profit);
    // cout<<"Hello World";

    return 0;
}
