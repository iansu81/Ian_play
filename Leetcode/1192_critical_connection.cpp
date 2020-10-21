class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // 把graph建立起來, 假設1,2是連在一起的, 1的adj要有2, 2的adj要有1
        vector<vector<int> > adj(n, vector<int>());
        for (int i = 0; i < connections.size(); ++i) {
        	int u = connections[i][0], v = connections[i][1];
        	adj[u].push_back(v);
        	adj[v].push_back(u);
        }
        // Mark all the vertices as not visited 
        vector<bool> visited(n, false); 
        vector<int> disc(n, INT_MAX), low(n, INT_MAX), parent(n, INT_MAX);
        vector<vector<int>> bridges;
        int time = 0;
        dfs(connections[0][0], adj, bridges, disc, low, visited, parent, time);

        return bridges;

    }



    // u: 現在要探索的vertex
    // disc[u]: discovery time 
    // low[u]: 用來紀錄dfs探索的時候,所有subtree最小的discovery time
    // parent: 紀錄dfs裡面的父節點


    void dfs(int u, vector<vector<int>> &adj, vector<vector<int>> &bridges, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<int> &parent, int &time)
    {
        visited[u] = true;
        disc[u] = low[u] = ++time;

        // 遍歷現在節點所有相鄰的節點
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];

            if(!visited[v])
            {
                parent[v] = u;
                // 對子結點做dfs,如果子結點有碰到u的ancestor, 子結點的low就會被update成那個ancestor的disc,
                // 如果父結點的low還是比那個ancestor大,也要繼續往父結點的父結點update下去
                dfs(v, adj, bridges, disc, low, visited, parent, time);
                low[u] = min(low[u], low[v]);


                // 當子結點做完ＤＦＳ之後的low 仍然大於父結點的discovery time的時候, 代表u 跟v中間只有一條路,所以就是一個bridge,
                if(low[v] > disc[u]){
                    bridges.push_back({u, v});
                }
            }
            // 此處就是碰到更之前父結點 ancestor, 所以v節點的low就要從原本的自己的discovery time update成那個ancestor節點的discovery time
            else if (v != parent[u])
            {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
};