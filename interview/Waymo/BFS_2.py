## 網格之多 Token 均等填充演算法

這是一個經典的**空間劃分**與**約束滿足問題（Constraint Satisfaction Problem）**，在自動駕駛的路徑規劃或地圖生成領域經常作為演算法考核題。

為了讓這道題目在技術規格上更清晰，我們將其拆解為「輸入定義」、「約束條件」與「輸出要求」三個維度。以下是更詳細、更具結構化的題目描述：

---

### 1. 問題概述

給定條件：** 給定一個大小為 $m \times n$ 的二維網格。
核心目標：** 將網格完全填滿，並使用四種不同的 Token（標記為 $T_1, T_2, T_3, T_4$）。
要求：** 在滿足特定空間結構約束的前提下，實現網格的**隨機化填充**。

### 2. 輸入規格

網格尺寸：** 整數 $m$ 與 $n$（其中 $m \times n$ 須為 4 的倍數）。
Token 集合：** $\{T_1, T_2, T_3, T_4\}$。

### 3. 核心約束條件 (Constraints)

等量分配 (Equal Distribution)：** 每個 Token 必須恰好佔據 $N = \frac{m \times n}{4}$ 個網格單元。
四連通性 (Four-Connectivity)：** 對於任何一種 Token $T_i$，其所佔據的所有單元必須通過「上、下、左、右」相鄰，構成一個**連通域（Connected Component）**，不允許出現斷裂。
完全覆蓋 (Full Coverage)：** 最終網格內所有單元格必須被標記，不得有剩餘的 `None` 或空值。
隨機性 (Randomness)：** 填充過程不應產生固定的幾何圖案（如固定的長條狀或區塊狀），結果應表現出足夠的空間隨機性。

### 4. 輸出要求

* 返回一個 $m \times n$ 的矩陣，其中每個元素 $grid[i][j]$ 儲存對應的 Token ID（1 至 4）。

---

### 💡 進階補充：面試中的澄清要點
若您在面試中遇到此題，為了展現您的思維嚴謹度，建議與面試官補充說明以下細節：
 📌 **關於「連通性」的定義**
 * 確認該連通性指的是「每個 Token 內部必須連通」，還是「這四個 Token 之間不能有互斥的屏障」。一般而言是指前者。
 
 
 📌 **關於「隨機性」的邊界**
 * 隨機性是否允許使用「機率式生長」？還是必須滿足「均勻分布」？
 * 若面試官要求極高的隨機性，可以提到使用 *Perlin Noise* 或 *Random Walk* 演算法來初始化種子。
 
 
 📌 **失敗場景 (Corner Cases)**
 * 當 $m$ 或 $n$ 為極小值（例如 $1 \times 4$）時，約束條件是否依然有效？
 * 若發生**「死鎖 (Deadlock)」**（即某個 Token 被其他三個圍困而無法擴展），是否允許重新隨機生成一次 (Retry)？
 


import random
from collections import deque

def populate_grid(m, n):
    """
    使用同步生長策略 (Multi-Source BFS) 填充網格，確保每個 Token 均等且連通。
    """
    # 每個 Token 的目標節點數量
    target = (m * n) // 4
    grid = [[None for _ in range(n)] for _ in range(m)]
    
    # queues: 儲存每個 Token 當前的邊界節點
    queues = {i: deque() for i in range(1, 5)}
    # count: 紀錄每個 Token 已佔用的總數
    count = {i: 0 for i in range(1, 5)}

    # 1. 初始化：隨機選取 4 個不重複的起始點
    for i in range(1, 5):
        r, c = random.randint(0, m-1), random.randint(0, n-1)
        # 若選到已被佔用的位置，重新隨機選擇
        while grid[r][c] is not None:
            r, c = random.randint(0, m-1), random.randint(0, n-1)
        grid[r][c] = i
        queues[i].append((r, c))
        count[i] += 1

    # 2. 同步 BFS 擴展
    # 只要還有 Token 未達到目標數量，就繼續進行迴圈
    while any(count[i] < target for i in range(1, 5)):
        for i in range(1, 5):
            # 若該 Token 尚未達標且仍有可擴展的邊界節點
            if count[i] < target and queues[i]:
                curr_r, curr_c = queues[i].popleft()
                
                # 為了達成「隨機性」，每次搜尋鄰居時都打亂方向優先序
                directions = [(0,1), (0,-1), (1,0), (-1,0)]
                random.shuffle(directions)
                
                for dr, dc in directions:
                    nr, nc = curr_r + dr, curr_c + dc
                    
                    # 邊界檢查：確保節點在網格內且尚未被任何 Token 佔領
                    if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] is None:
                        grid[nr][nc] = i
                        queues[i].append((nr, nc))
                        count[i] += 1
                        
                        # 若數量達標，停止此 Token 的擴展
                        if count[i] == target: 
                            break
                            
    # 注意：此版本在極端網格條件下可能導致死鎖 (Deadlock)
    # 建議面試時提到：若 count[i] < target 且 queues[i] 為空，應觸發重新洗牌 (Retry)
    return grid


如果您在面試中解釋這段程式碼，建議口頭補充以下兩點，這會顯示您具備系統設計的思維：

關於同步 (Synchronization)：
「我使用了 for i in range(1, 5) 的迴圈來處理四個 Queue，這確保了每個 Token 在每一輪擴展中都有公平的『生存機會』，避免某一個 Token 過快佔據中心空間而封鎖了其他 Token。」

關於死鎖防禦 (Deadlock Prevention)：
「對於小型的網格或特定的隨機起點，可能會發生某個 Token 被其他三個完全包圍導致無法擴展。實務上，我會在外層包裝一個『重試機制 (Retry Mechanism)』，並設置一個最大重試次數，以確保演算法在所有情況下都能穩定輸出結果。」