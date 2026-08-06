from collections import deque
from typing import List, Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class BFSPractice:
    def level_order(self, root: Optional[TreeNode]) -> List[List[int]]:
        """
        1. 二元樹層序追蹤 (LeetCode 102: Binary Tree Level Order Traversal)
        核心: 使用 deque (雙端隊列) 搭配 level_size 進行逐層走訪
        """
        if not root:
            return []

        result = []
        queue = deque([root])

        while queue:
            level_size = len(queue)  # 當前層的節點數量
            current_level = []

            for _ in range(level_size):
                node = queue.popleft()
                current_level.append(node.val)

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            result.append(current_level)

        return result

    def num_islands(self, grid: List[List[str]]) -> int:
        """
        2. 2D 網格搜尋 / 島嶼數量 (LeetCode 200: Number of Islands)
        核心: 遇上陸地 ('1') 觸發 BFS，將相連陸地標記為已造訪 ('0')
        """
        if not grid or not grid[0]:
            return 0

        rows, cols = len(grid), len(grid[0])
        islands_count = 0

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1":
                    islands_count += 1
                    # 開始 BFS
                    queue = deque([(r, c)])
                    grid[r][c] = "0"  # 標記為已造訪

                    while queue:
                        curr_r, curr_c = queue.popleft()
                        # 上下左右 4 個方向
                        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                            nr, nc = curr_r + dr, curr_c + dc
                            if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == "1":
                                grid[nr][nc] = "0"  # 造訪後立即標記，避免重複加入 queue
                                queue.append((nr, nc))

        return islands_count

    def shortest_path_binary_matrix(self, grid: List[List[int]]) -> int:
        """
        3. 2D 矩陣最短路徑 (LeetCode 1091: Shortest Path in Binary Matrix)
        核心: 8 方向 BFS 尋找起點 (0,0) 到終點 (n-1, n-1) 的最短步數
        BFS 第一次到達終點時的步數即為最短步數。
        """
        n = len(grid)
        if grid[0][0] != 0 or grid[n - 1][n - 1] != 0:
            return -1

        if n == 1:
            return 1

        queue = deque([(0, 0, 1)])  # (row, col, current_distance)
        grid[0][0] = 1  # 標記已造訪

        # 8 方向 (包含對角線)
        directions = [
            (-1, -1), (-1, 0), (-1, 1),
            (0, -1),           (0, 1),
            (1, -1),  (1, 0),  (1, 1)
        ]

        while queue:
            r, c, dist = queue.popleft()

            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and grid[nr][nc] == 0:
                    if nr == n - 1 and nc == n - 1:
                        return dist + 1
                    grid[nr][nc] = 1  # 標記已造訪
                    queue.append((nr, nc, dist + 1))

        return -1


if __name__ == "__main__":
    sol = BFSPractice()

    # 測試 1: 二元樹層序追蹤
    #       3
    #      / \
    #     9  20
    #       /  \
    #      15   7
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20, TreeNode(15), TreeNode(7))
    print("Level Order Traversal:", sol.level_order(root))
    # 預期輸出: [[3], [9, 20], [15, 7]]

    # 測試 2: 島嶼數量
    grid1 = [
        ["1", "1", "1", "1", "0"],
        ["1", "1", "0", "1", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "0", "0", "0"]
    ]
    print("Number of Islands:", sol.num_islands(grid1))
    # 預期輸出: 1

    # 測試 3: 最短路徑
    grid2 = [
        [0, 0, 0],
        [1, 1, 0],
        [1, 1, 0]
    ]
    print("Shortest Path in Binary Matrix:", sol.shortest_path_binary_matrix(grid2))
    # 預期輸出: 4
