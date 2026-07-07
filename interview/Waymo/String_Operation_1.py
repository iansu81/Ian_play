題目要求將壓縮格式的字串（例如 a(b(c){2}){2}）展開成原始字串。
題目分析這個問題的規律是：普通字元：直接加入結果。
遇到 (：表示進入一個新的子字串處理層級，需要將後續內容與當前的解析結果分開。遇到 )：表示當前層級結束，接著會讀取後方的 {數字}，
將該子字串重複對應次數並加回上一層。由於存在巢狀結構（a(b(c){2}){2} 中有套圈的情況），
最適合使用 堆疊 (Stack) 或 遞迴 (Recursion) 來處理。
解題邏輯 (使用堆疊)使用兩個堆疊分別記錄：stringStack：記錄進入括號前的字串片段。
countStack：記錄括號後面的重複次數。處理步驟：遍歷字串，如果是字母，直接添加到目前的 currentString。
遇到 (，將目前的 currentString 壓入 stringStack，並重置 currentString。遇到 )，
讀取後面的數字 k。將 currentString 重複 k 次，再取出 stringStack 的內容與之拼接，更新為新的 currentString。

def decodeString(s: str) -> str:
    stack = []
    current_string = ""
    i = 0
    
    while i < len(s):
        if s[i].isalpha():
            current_string += s[i]
        elif s[i] == '(':
            stack.append(current_string)
            current_string = ""
        elif s[i] == ')':
            # 找到後面的數字 {k}
            i += 2 # 跳過 '){'
            num_str = ""
            while s[i] != '}':
                num_str += s[i]
                i += 1
            k = int(num_str)
            
            # 展開並拼接
            prev_string = stack.pop()
            current_string = prev_string + (current_string * k)
        i += 1
        
    return current_string

# 測試範例
print(decodeString("abscscsg"))        # 輸出: abscscsg
print(decodeString("a(b(c){2}){2}"))  # 輸出: abccbcc


複雜度分析時間複雜度：$O(n)$，其中 $n$ 是結果字串的長度，
因為我們遍歷了每個字元並進行了相應的拼接。
空間複雜度：$O(m)$，其中 $m$ 是嵌套的深度，主要取決於堆疊的大小。