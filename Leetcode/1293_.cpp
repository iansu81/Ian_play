#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;



class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        // A 2D array to record the visted node, -1 means it has not been visited. 
        // The value represents that the number of obstacles we can still remove at this node.
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), -1));
        
        // Use a queue to record the node we are going to visit
        queue<vector<int>> q;

        // {x,y, number of steps we have gone, number of obstacles we can still remove}
        q.push({0,0,0,k});

        while(!q.empty()) {
            vector<int> p = q.front();
            q.pop();
           
            // If the node is out of boundary, ignore it.
            if(p[0] < 0 || p[0] >= grid.size() || p[1] < 0 || p[1] >= grid[0].size())
                continue;

            // If we have reached the bottom-right node, return the number of steps we have gone.
            if(p[0] == (grid.size()-1) && p[1] == (grid[0].size()-1)) return p[2];


            // If we run into an obstacle, check if we can still remove it. Otherwise, ignore this node and its following nodes.
            if(grid[p[0]][p[1]] == 1) {
                if(p[3] > 0) {
                    p[3]--;
                }
                else continue; 
            }

            // If the previous visit has more number of obstacle we can remove, then we ignore the current visit.
            if(visited[p[0]][p[1]] >= p[3] && visited[p[0]][p[1]] != -1) continue; 
            
            // Update the number of obstacle this node can still remove.
            visited[p[0]][p[1]] = p[3];

            // 第三項一定要用p[2]+1不能用p[2]++,否則他會每次都把p[2]+1
            // Visted the 4 directional nodes.
            q.push({p[0]-1, p[1], p[2]+1, p[3]});
            q.push({p[0], p[1]-1, p[2]+1, p[3]});
            q.push({p[0]+1, p[1], p[2]+1, p[3]});
            q.push({p[0], p[1]+1, p[2]+1, p[3]});
        }

        return -1;
    }
};



int main()
{
    vector<vector<int>> test{{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
    Solution sol;
    std::cout << sol.shortestPath(test, 1) << std::endl;
}

