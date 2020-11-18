#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:

    // 找目前數字的源頭, 如果沒有其他的朋友, 源頭就是自己本身, 否則就是繼續找parent, 一直到找到parent[num] = -1
    int find(int num, vector<int> &parent)
    {
        if(parent[num] != -1) return find(parent[num], parent);
        return num;
    }
    // 找x跟y的源頭, 如果x,y源頭不一樣, 最後要變成一樣的
    void union_element(vector<int> &parent, int x, int y)
    {
        int parent_x = find(x, parent);
        int parent_y = find(y, parent);
        // 注意！！當源頭不一樣的時候, 要parent[parent_x] = parent_y 而不是parent[x] = y,
        // 後者會一直reset x的parent而不是合併兩個group
        if( parent_x != parent_y) parent[parent_x] = parent_y;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int num_pple = M.size();
        vector<int> parent(num_pple, -1);
        for(int i = 0; i < num_pple; i++)
        {
            for(int j = i+1; j < num_pple; j++)
            {
                if( M[i][j] == 1 ) union_element(parent, i, j); 
            }

        }
        // 最後只紀錄源頭數量,就可以得知有多少group
        int ans = 0;
        for(int i = 0; i < num_pple; i++)
        {
            if(parent[i] == -1) ans++;
        }
        return ans;

    }
};


int main()
{
    vector<vector<int>> test {{1,0,0,1},
                            {0,1,1,0},
                            {0,1,1,1},
                            {1,0,1,1}};
                                Solution sol;
    cout << "Ans: " << sol.findCircleNum(test) << endl;
}

