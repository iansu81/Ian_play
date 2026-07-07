題目分析你需要找出網格中所有由相同顏色構成的「正方形」。輸入：一個包含多種顏色（如 A, B, C, D）的二維 Grid。
思路：遍歷 Grid，對每個尚未訪問的點進行 BFS（或 DFS），將所有相連且顏色相同的點標記為已訪問並存儲起來。
對存儲起來的同一顏色座標集合，檢查它們是否構成正方形：找到該顏色區域的最小和最大行/列座標（min_r, max_r, min_c, max_c）。
檢查長寬是否相等（max_r - min_r == max_c - min_c）。
檢查該區域內元素的數量是否等於面積（(max_r - min_r + 1) * (max_c - min_c + 1)）。
Python 參考代碼這段代碼展示了如何遍歷網格並識別符合條件的區域：

關鍵細節提示邊界條件：代碼中使用了 len(coords) == height * width 來確保該區域是一個「實心」的正方形，
這能有效排除掉形狀不規則或中間有缺口的相同顏色塊。
複雜度：時間複雜度為 $O(R \times C)$，其中 $R$ 為行數，$C$ 為列數，因為每個點只會被 BFS 訪問一次。
這道題目的核心在於「連通性檢查」與「幾何條件判斷」的結合，面試時如果遇到，建議先向面試官確認：
該顏色區域是否要求必須是「矩形」還是「任意連通塊」，這會影響你的判斷邏輯。


def count_square_regions(grid):
    # 如果網格為空，直接返回 0
    if not grid or not grid[0]:
        return 0
    
    rows, cols = len(grid), len(grid[0])
    visited = set()  # 用來記錄已經訪問過的座標，避免重複計算
    square_count = 0

    # 定義一個內部函數，用來找出與當前點顏色相同的所有連通區域
    def get_region(r, c, color):
        queue = [(r, c)]
        visited.add((r, c))
        region_coords = []
        
        while queue:
            curr_r, curr_c = queue.pop(0)
            region_coords.append((curr_r, curr_c))
            
            # 檢查上下左右四個方向
            for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nr, nc = curr_r + dr, curr_c + dc
                # 確認新座標在網格內，且顏色相同、未被訪問過
                if 0 <= nr < rows and 0 <= nc < cols and \
                   (nr, nc) not in visited and grid[nr][nc] == color:
                    visited.add((nr, nc))
                    queue.append((nr, nc))
        return region_coords

    # 遍歷網格中的每一個點
    for r in range(rows):
        for c in range(cols):
            # 如果這個點還沒被訪問過，說明發現了一個新的顏色區域
            if (r, c) not in visited:
                color = grid[r][c]
                # 獲取該區域內所有相同顏色的座標
                coords = get_region(r, c, color)
                
                # 計算該區域的邊界座標，以判斷其形狀
                rs = [p[0] for p in coords]
                cs = [p[1] for p in coords]
                
                min_r, max_r = min(rs), max(rs)
                min_c, max_c = min(cs), max(cs)
                
                # 計算區域的長與寬
                height = max_r - min_r + 1
                width = max_c - min_c + 1
                
                # 正方形判斷邏輯：
                # 1. 長必須等於寬 (height == width)
                # 2. 實際收集到的點數量必須等於面積 (height * width)，
                #    這能確保該區域是個完整的「實心」正方形，而非缺角或鏤空的形狀。
                if height == width and len(coords) == height * width:
                    square_count += 1
                    
    return square_count

# 測試範例
grid = [
    ['A', 'A', 'B'],
    ['A', 'A', 'B'],
    ['C', 'C', 'C']
]
print(f"找到的正方形數量: {count_square_regions(grid)}")


重點解析：為什麼要用 visited 集合？
：因為 BFS 會一次把整塊相同顏色的區域找出來。如果我們不標記，遍歷到區域內的第二個點時，又會重複計算一遍，導致結果錯誤。

為什麼要比較 len(coords) 與面積？
：題目要求找「正方形」，單純看長寬相等是不夠的（例如一個 U 字型的區域，其外框長寬也可能相等）。
計算面積是確保該區域內部沒有被其他顏色切斷或留空，必須是「填滿」的。

時間複雜度：這段算法的時間複雜度為 $O(R \times C)$，因為每一個格點在最壞的情況下只會被遍歷並加入 visited 集合一次，
效率在面試中是非常理想的。