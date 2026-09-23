class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxreach = 0
        length = len(nums)
        for i in range(length):
            if i > maxreach:
                return False
            
            maxreach = max(maxreach, i + nums[i])
            if maxreach > (lengh-1):
                return True
        return True



# 不可以用以下寫法, 有兩個盲點:
# 1. 若無法走到該位置： 例如 [0, 2, 3]，迴圈走到第 1 格（值為 2）時會判斷能到達終點並回傳 True，但實際上第 0 格為 0，根本走不到第 1 格。
# 2. 單一元素陣列： 當 nums = [0] 時，起點即終點應回傳 True，但 range(0) 不會執行迴圈，會直接跑到最後回傳 False。
# class Solution:
#     def canJump(self, nums: List[int]) -> bool:
#         length = len(nums)
#         for i in range(length-1):
#             if (i+ nums[i] >= (length-1)):
#                 return True
#         return False