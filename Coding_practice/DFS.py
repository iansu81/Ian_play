from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class DFSPractice:
    # -------------------------------------------------------------
    # 1. 前序走訪 (Preorder Traversal: Root -> Left -> Right)
    # -------------------------------------------------------------
    def preorder_recursive(self, root: Optional[TreeNode]) -> List[int]:
        """前序走訪 - 遞迴寫法 (Recursive)"""
        res = []

        def dfs(node):
            if not node:
                return
            res.append(node.val)
            dfs(node.left)
            dfs(node.right)

        dfs(root)
        return res

    def preorder_iterative(self, root: Optional[TreeNode]) -> List[int]:
        """前序走訪 - 迭代寫法 (Iterative using Stack)"""
        if not root:
            return []

        res = []
        stack = [root]

        while stack:
            node = stack.pop()
            res.append(node.val)
            # 因為 Stack 是 LIFO (後進先出)，所以右子樹先入棧，左子樹後入棧
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)

        return res

    # -------------------------------------------------------------
    # 2. 中序走訪 (Inorder Traversal: Left -> Root -> Right)
    # -------------------------------------------------------------
    def inorder_recursive(self, root: Optional[TreeNode]) -> List[int]:
        """中序走訪 - 遞迴寫法 (Recursive)"""
        res = []

        def dfs(node):
            if not node:
                return
            dfs(node.left)
            res.append(node.val)
            dfs(node.right)

        dfs(root)
        return res

    def inorder_iterative(self, root: Optional[TreeNode]) -> List[int]:
        """中序走訪 - 迭代寫法 (Iterative using Stack)"""
        res = []
        stack = []
        curr = root

        while curr or stack:
            # 一直向左走，將沿途節點放入 Stack
            while curr:
                stack.append(curr)
                curr = curr.left

            # 彈出最左邊的節點處理
            curr = stack.pop()
            res.append(curr.val)

            # 轉向右子樹
            curr = curr.right

        return res

    # -------------------------------------------------------------
    # 3. 後序走訪 (Postorder Traversal: Left -> Right -> Root)
    # -------------------------------------------------------------
    def postorder_recursive(self, root: Optional[TreeNode]) -> List[int]:
        """後序走訪 - 遞迴寫法 (Recursive)"""
        res = []

        def dfs(node):
            if not node:
                return
            dfs(node.left)
            dfs(node.right)
            res.append(node.val)

        dfs(root)
        return res

    def postorder_iterative(self, root: Optional[TreeNode]) -> List[int]:
        """
        後序走訪 - 迭代寫法 (Iterative using Stack)
        技巧: 改寫前序 (Root -> Right -> Left)，最後將結果反轉即為 (Left -> Right -> Root)
        """
        if not root:
            return []

        res = []
        stack = [root]

        while stack:
            node = stack.pop()
            res.append(node.val)
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)

        return res[::-1]

    # -------------------------------------------------------------
    # 4. 2D 網格島嶼最大面積 (LeetCode 695: Max Area of Island)
    # -------------------------------------------------------------
    def max_area_of_island_recursive(self, grid: List[List[int]]) -> int:
        """2D 網格 DFS - 遞迴寫法"""
        if not grid or not grid[0]:
            return 0

        rows, cols = len(grid), len(grid[0])

        def dfs(r, c):
            if r < 0 or r >= rows or c < 0 or c >= cols or grid[r][c] == 0:
                return 0

            grid[r][c] = 0  # 標記已造訪
            area = 1
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                area += dfs(r + dr, c + dc)
            return area

        max_area = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    max_area = max(max_area, dfs(r, c))

        return max_area

    def max_area_of_island_iterative(self, grid: List[List[int]]) -> int:
        """2D 網格 DFS - 迭代寫法 (Iterative Stack)"""
        if not grid or not grid[0]:
            return 0

        rows, cols = len(grid), len(grid[0])
        max_area = 0

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    current_area = 0
                    stack = [(r, c)]
                    grid[r][c] = 0  # 標記已造訪

                    while stack:
                        curr_r, curr_c = stack.pop()
                        current_area += 1

                        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                            nr, nc = curr_r + dr, curr_c + dc
                            if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1:
                                grid[nr][nc] = 0  # 放入 stack 時立即標記已造訪
                                stack.append((nr, nc))

                    max_area = max(max_area, current_area)

        return max_area


if __name__ == "__main__":
    sol = DFSPractice()

    # 建立測試用二元樹:
    #       1
    #      / \
    #     2   3
    #    / \
    #   4   5
    root = TreeNode(1)
    root.left = TreeNode(2, TreeNode(4), TreeNode(5))
    root.right = TreeNode(3)

    print("--- 樹的遍歷比較 ---")
    print("Preorder Recursive: ", sol.preorder_recursive(root))
    print("Preorder Iterative: ", sol.preorder_iterative(root))

    print("Inorder Recursive:  ", sol.inorder_recursive(root))
    print("Inorder Iterative:  ", sol.inorder_iterative(root))

    print("Postorder Recursive:", sol.postorder_recursive(root))
    print("Postorder Iterative:", sol.postorder_iterative(root))

    # 網格測試
    grid_rec = [
        [0, 0, 1, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 1, 0, 0, 1],
        [0, 1, 0, 0, 1]
    ]
    grid_ite = [row[:] for row in grid_rec]

    print("\n--- 2D 網格島嶼最大面積 ---")
    print("Max Area (Recursive):", sol.max_area_of_island_recursive(grid_rec))
    print("Max Area (Iterative):", sol.max_area_of_island_iterative(grid_ite))
