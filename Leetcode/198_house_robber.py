
"""
當依序考慮到第 i 間房屋時，只有兩種互斥的選擇：

1. 不偷第 i 間：
   收益為前 i-1 間房屋能拿到的最大金額 -> dp[i-1]

2. 偷第 i 間：
   第 i-1 間絕對不能偷，收益為前 i-2 間的最大金額加上此間金額 -> dp[i-2] + nums[i]

狀態轉移方程：
dp[i] = max(dp[i-1], dp[i-2] + nums[i])
"""

class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = []
        n = len(nums)
        if n <= 2:
            return max(nums)
        # 注意: dp[0] 是只考慮第 0 間，dp[1] 是前兩間取最大
        dp.extend([nums[0], max(nums[0],nums[1])])
        for i in range(2, n):
            dp.append(max(dp[i-1], dp[i-2]+nums[i]))
        return dp[n-1]