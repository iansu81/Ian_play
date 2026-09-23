class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])



        def dfs(i: int, j: int, k: int):
            # board[i][j] != word[k]的check 要在最後一步, 不然可能會報index error
            if (i < 0 or i >= m or j <0 or j >=n or (board[i][j] != word[k]) ):
                return False
            
            # 這一步不能放在function 最前面, 不然還沒檢查最後一個單字就return True了
            if k == (len(word) - 1):
                return True 

            # 這一步要在邊界檢查之後, 不然如果i或j是-1, 就會抓取最後一行或最後一列, 而不會報錯
            tmp = board[i][j]
            
            
            board[i][j] = '#'

            found = ( dfs(i-1, j, k+1) or dfs(i, j-1, k+1) or dfs(i+1, j, k+1) or dfs(i, j+1,k+1))

            board[i][j] = tmp
            
            return found
        


        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True 
        return False


優化:
1. 字元頻率與長度預檢查（Character Frequency Check）：
在進入 DFS 前，先統計 board 與 word 的字元出現次數。若字串長度超過棋盤總格數，
或棋盤內某字元的數量少於 word 所需數量，直接回傳 False，完全省去遞迴開銷。

2. 稀有字元起點優化（Reverse Word Search）：
比較 word[0] 與 word[-1] 在棋盤中出現的次數。若開頭字母在棋盤中出現的次數比結尾字母多，
直接將字串反轉（word = word[::-1]）再搜尋。從出現頻率較低的字母當作 DFS 起點，能大幅降低搜尋樹的分支數量。

code: 將以下加入dfs 前
# 1. 長度剪枝
        if len(word) > m * n:
            return False

        # 2. 詞頻剪枝
        board_counts = Counter(char for row in board for char in row)
        word_counts = Counter(word)
        for char, count in word_counts.items():
            if board_counts[char] < count:
                return False

        # 3. 起點稀有度優化（若結尾字元較少，反轉搜尋）
        if board_counts[word[0]] > board_counts[word[-1]]:
            word = word[::-1]