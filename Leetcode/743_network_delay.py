class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        
        # graph一定要用default dict, 並且要pass list進去argument,
        # 如果用一般的dict, 會因為u 不再dict裡面報錯, 沒有pass list 進去也會報錯
        graph = defaultdict(list)

        for u,v,w in times:
            graph[u].append((v, w))

        dist_table = [(0, k)]
        visited = {}
        while dist_table :        
            dist, node = heapq.heappop(dist_table)
            
            # 這個check一定要在pop出來立刻做, 不然後面的資料可能會覆蓋掉錢ㄉㄧㄜ˙
            if node in visited:
                    continue
            visited[node] = dist

            for neighbor, new_dist in graph[node]:

                # push進去heap之前先檢查, 如果已經
                if neighbor not in visited:
                    heapq.heappush(dist_table, (dist+new_dist, neighbor))

        # 如果長度不一樣, 代表已經尋訪過所有的node一次, 仍有node沒有被讀取到
        if len(visited) != n:
            return -1
        else:
            return max(visited.values())

    