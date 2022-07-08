
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 建立一個graph來描述要上某一門課之前要上的先修課
        vector<vector<int>> graph( numCourses, vector<int>());
        for(auto& prereq: prerequisites) {
            graph[prereq[0]].push_back(prereq[1]);
        }
        vector<int> result;

        // 儲存每一個course的state// 0代表尚未被訪問過, 1代表正在被訪問中, 2代表已經訪問完了要加入結果中
        
        vector<int> status_record(numCourses, 0);
        for(int i = 0; i < graph.size(); i++) {
            // 如果state 1的課程的先修課又找回自己, 就代表有環, 這樣就不能使用topological sort去排序, 要返回empty的vector,
            // 一定要加這個check, 否則會有一個bug, ex: [[1,0],[1,2], [0,1],] 這樣就會返回[2] 而不是empty vector
            if(!tpsort(i, status_record, graph, result)) return vector<int>();
        }
        return result;
    }

    bool tpsort(const int& course, vector<int>& status_record, vector<vector<int>>& graph, vector<int>& result){


        if(status_record[course] == 2) return true;
        if(status_record[course] == 1) return false;
        status_record[course] = 1;
        for(int i = 0;i < graph[course].size(); i ++) {
            if(!tpsort(graph[course][i], status_record, graph, result)) return false;
        }
        status_record[course] = 2;
        result.push_back(course);
        return true;

    }
};



int main()
{
    Solution sol;
    vector<vector<int>> test{{1,0},{2,0},{3,1},{3,2}};

    auto ans = sol.findOrder(4, test);

    for(auto& a: ans) {
        cout << a << ",";
    }
    cout << endl;

}