from typing import List

class PrefixSumPractice:
    def subarray_sum(self, nums: List[int], k: int) -> int:
        """
        LeetCode 560: Subarray Sum Equals K
        求陣列中連續子陣列和等於 k 的總個數。
        
        時間複雜度: O(N)
        空間複雜度: O(N)
        """
        # prefix_count[s] 紀錄前綴和為 s 出現的次數
        # 初始前綴和 0 出現 1 次（代表從頭開始的子陣列）
        prefix_count = {0: 1}
        current_sum = 0
        ans = 0

        for num in nums:
            current_sum += num
            
            # 如果 current_sum - k 出現在 prefix_count 中
            # 代表存在某個過去的前綴和，使得 (current_sum - past_prefix_sum) = k
            if (current_sum - k) in prefix_count:
                ans += prefix_count[current_sum - k]
            
            # 更新當前前綴和的出現次數
            prefix_count[current_sum] = prefix_count.get(current_sum, 0) + 1

        return ans

    def max_sub_array_len(self, nums: List[int], k: int) -> int:
        """
        變體題: 找到「最長」的連續子陣列長度，使其和等於 k。
        LeetCode 325: Maximum Size Subarray Sum Equals k
        
        時間複雜度: O(N)
        空間複雜度: O(N)
        """
        # prefix_index[s] 紀錄前綴和 s 「第一次出現」的索引 idx
        prefix_index = {0: -1}
        current_sum = 0
        max_len = 0

        for i, num in enumerate(nums):
            current_sum += num

            # 如果存在過去的前綴和等於 current_sum - k
            if (current_sum - k) in prefix_index:
                max_len = max(max_len, i - prefix_index[current_sum - k])

            # 只要存第一次出現的位置即可，這樣才能維持最長長度
            if current_sum not in prefix_index:
                prefix_index[current_sum] = i

        return max_len

    def subarrays_div_by_k(self, nums: List[int], k: int) -> int:
        """
        變體題: LeetCode 974: Subarray Sums Divisible by K
        求連續子陣列和能被 k 整除的總個數。
        
        核心思維: (prefix_i - prefix_j) % k == 0  =>  prefix_i % k == prefix_j % k
        """
        # mod_count 紀錄前綴和餘數出現的次數
        mod_count = {0: 1}
        current_sum = 0
        ans = 0

        for num in nums:
            current_sum += num
            # Python % k 會自動處理負數餘數（保持非負）
            mod = current_sum % k
            
            if mod in mod_count:
                ans += mod_count[mod]

            mod_count[mod] = mod_count.get(mod, 0) + 1

        return ans


if __name__ == "__main__":
    sol = PrefixSumPractice()

    # Test Case 1: Subarray Sum Equals K
    nums1 = [1, 1, 1]
    k1 = 2
    print(f"LeetCode 560 - nums={nums1}, k={k1} -> Result: {sol.subarray_sum(nums1, k1)} (Expected: 2)")

    nums2 = [1, 2, 3, -2, 2, 1]
    k2 = 3
    print(f"LeetCode 560 - nums={nums2}, k={k2} -> Result: {sol.subarray_sum(nums2, k2)} (Expected: 5)")

    # Test Case 2: Max Subarray Length Equals K
    nums3 = [1, -1, 5, -2, 3]
    k3 = 3
    print(f"Max Subarray Len - nums={nums3}, k={k3} -> Result: {sol.max_sub_array_len(nums3, k3)} (Expected: 4, [1, -1, 5, -2])")

    # Test Case 3: Subarray Sums Divisible by K
    nums4 = [4, 5, 0, -2, -3, 1]
    k4 = 5
    print(f"LeetCode 974 - nums={nums4}, k={k4} -> Result: {sol.subarrays_div_by_k(nums4, k4)} (Expected: 7)")
