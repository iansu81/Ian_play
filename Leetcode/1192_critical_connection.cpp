class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // 把graph建立起來
        vector<vector<int> > adj(n, vector<int>());
        for (int i = 0; i < connections.size(); ++i) {
        	int u = connections[i][0], v = connections[i][1];
        	adj[u].push_back(v);
        	adj[v].push_back(u);
        }
        // Mark all the vertices as not visited 
        bool *visited = new bool[V]; 
        int *disc = new int[V]; 
        int *low = new int[V]; 
        int *parent = new int[V]; 
  
        // Initialize parent and visited arrays 
        for (int i = 0; i < V; i++) 
        { 
            parent[i] = NIL; 
            visited[i] = false; 
        } 
  
        // Call the recursive helper function to find Bridges 
        // in DFS tree rooted with vertex 'i' 
        for (int i = 0; i < V; i++) 
            if (visited[i] == false) 
                bridgeUtil(i, visited, disc, low, parent); 


    }
};