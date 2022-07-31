


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        // dp[i]代表走到i floor的時候, 最少的cost
        // 比size多一個因為這樣才能紀錄最後一步的dp
        vector<int> dp(cost.size()+1);

        // 從第二階開始, 因為可以從cost[0]或cost[1]比較低的那一個開始
        // 每次又可以走一階或兩階, 所以要找前面兩個比較小的
        for(int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[cost.size()];
        
    }
};