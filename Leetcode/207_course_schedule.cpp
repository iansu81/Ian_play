#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> req_graph(numCourses, vector<int>() );
        vector<int> course_state(numCourses, 0); // 0: has not been visited, 1: visting, 2: visited
        make_graph(req_graph, prerequisites);

        // 記得要遍歷所有的course
        for(int i = 0 ; i < numCourses; i++ )
        {
            if (!toposort(i, req_graph, course_state)) return false;
        }
        return true;
    }

    // 建立一個graph, key: 課程, value: 先修課
    void make_graph(vector<vector<int>>& graph, vector<vector<int>>& prerequisites)
    {
        for(const auto& course: prerequisites)
        {
            graph[course[0]].push_back(course[1]);
        }
    }

    // topological sort 每次得到的解不一定一樣, 但是如果有環, 就不能做topological sort,
    // 所以第一次visit 一個node的時候, 把這個node 的state mark成1, 然後往他的先修課下去找, 如果找先修課又找回自己, 就代表有環

    bool toposort(int visiting_course, vector<vector<int>> &graph, vector<int> &course_state)
    {
        // 當一個course被mark成state 2 代表他跟他的先修課, 都是沒有問題的, 就不用再繼續找下去, 直接return true
        // 繼續找下去也是浪費時間
        if(course_state[visiting_course] == 2) return true;
        if(course_state[visiting_course] == 1) return false;
        course_state[visiting_course] = 1;
        bool ans = true;
        for(const auto& c: graph[visiting_course])
        {
            ans = toposort(c, graph, course_state);
            if(!ans) return false;
        }

        course_state[visiting_course] = 2;
        return ans;
    }

};

int main()
{
    Solution sol;
    vector<vector<int>> test{{2, 0}, {1, 0}, {3, 1}, {3, 2}, {1, 3}};

    cout << "Ans: " << sol.canFinish(4, test) << endl;

}