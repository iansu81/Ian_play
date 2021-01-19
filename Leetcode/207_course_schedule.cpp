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

    bool toposort(int visiting_course, vector<vector<int>> &graph, vector<int> &course_state)
    {
        if(course_state[visiting_course] == 2) return true;
        if(course_state[visiting_course] == 1) return false;
        course_state[visiting_course] = 1;
        bool ans = true;
        for(const auto& c: graph[visiting_course])
        {
            ans = toposort(c, graph, course_state);
            if(!ans) cout << "AAAAAAA" << endl;
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