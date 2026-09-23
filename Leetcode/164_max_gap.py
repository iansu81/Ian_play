class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        n = len(nums)
        # 1. 邊界條件：元素個數小於 2，無法構成間距，直接回傳 0
        if n < 2:
            return 0

        # 2. 找出全域極值，用於確定資料涵蓋的總區間範圍
        min_val = min(nums)
        max_val = max(nums)

        # 3. 計算桶的大小 (bucket_size) 與數量 (bucket_count)
        # 根據鴿籠原理：n 個數字分佈在 n-1 個間隔中，平均間隔為 (max - min) / (n - 1)
        # 設定桶大小為平均間隔，可以保證「最大差距」絕對不可能出現在同一個桶內部
        # bucket_size 使用 max(1, ...)：避免整數除法向下取整為 0，防範後續的 ZeroDivisionError。
        bucket_size = max(1, (max_val - min_val) // (n - 1))

        # bucket_count 加 1：0-based 索引需容納最大值 max_val 映射出的最高 index，防止 IndexError。
        bucket_count = (max_val - min_val) // bucket_size + 1
     

        # 4. 初始化桶：每個桶僅需儲存該桶內的 [最小值, 最大值]
        # 初始值設為 [inf, -inf]，方便後續透過 min/max 更新，同時也作為空桶的標記
        buckets = [[float("inf"), float("-inf")] for _ in range(bucket_count)]

        # 5. 將所有數字映射到對應的桶中（分配過程 O(n)）
        for num in nums:
            idx = (num - min_val) // bucket_size
            buckets[idx][0] = min(buckets[idx][0], num)  # 更新桶內最小值
            buckets[idx][1] = max(buckets[idx][1], num)  # 更新桶內最大值

        # 6. 計算跨桶之間的最大差距
        # min_val 必定落在 buckets[0]，因此 buckets[0] 絕非空桶，可直接作為初始 prev_max
        prev_max = buckets[0][1]
        max_difference = 0

        # 走訪每個桶，只需比對「相鄰非空桶」之間的距離
        for b_min, b_max in buckets:
            # 若 b_min 為 inf，代表此桶為空桶，直接跳過
            if b_min != float("inf"):
                # 間距 = 當前非空桶的最小值 - 前一個非空桶的最大值
                max_difference = max(max_difference, b_min - prev_max)
                # 更新前一個非空桶的最大值，作為下一輪比對的基準
                prev_max = b_max

        return max_difference