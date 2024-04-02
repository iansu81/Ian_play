#include <iostream>
#include <vector>
using namespace std;

int max_depth = 0;

void dfs(vector<vector<int>>& graph, int max_val, int i, int j){

    max_depth = max(max_depth, max_val);
    if( (i-1) >= 0 && graph[i-1][j] < graph[i][j]) {
        dfs(graph, max_val+1, i-1, j); 
    }

    if( (i+1) < graph.size()  && graph[i+1][j] < graph[i][j]) {
        dfs(graph, max_val+1, i+1, j); 
        
    }
    
    if( (j-1) >= 0 && graph[i][j-1] < graph[i][j]) {
        dfs(graph, max_val+1, i, j-1);
    }
    
    if( (j+1) < graph[i].size() && graph[i][j+1] < graph[i][j]) {

        dfs(graph, max_val+1, i, j+1);
    }
        
}




int calculate_depth(vector<vector<int>> graph){
    int max_val = 0;
    for(int x = 0; x < graph.size(); x++) {
        for(int y = 0; y < graph[x].size(); y++) {
           
            dfs(graph, max_val, 2, 2);
        }
        
    }
    return max_depth;
    
    
}




int main()
{
    vector<vector<int>> test{{1,2,3,4,5},
                            {16,17,18,19,6},
                            {15,24,25,20,7},
                            {14,23,22,21,8},
                            {13,12,11,10,9}};
    cout<<calculate_depth(test);

    return 0;
}