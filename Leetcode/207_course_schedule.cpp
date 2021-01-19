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
        
        // return toposort(0, req_graph, course_state );
        return true;
    }


    void make_graph(vector<vector<int>>& graph, vector<vector<int>>& prerequisites)
    {
        for(const auto& course: prerequisites)
        {
            graph[course[0]].push_back(course[1]);
        }
    }

    // bool toposort(int visiting_course, vector<vector<int>>& graph, vector<int>＆ course_state)
    // {
    //     if(course_state[visiting_course] == 1) return false;
    //     course_state[visiting_course] = 1;
    //     bool ans = true;
    //     for(const auto& c: graph[visiting_course])
    //     {
    //         ans = toposort(c, graph, course_state);
    //         if(!ans) return false;
    //     }

    //     course_state[visiting_course] = 2;
    //     return ans;
    // }

};


int main()
{
    Solution sol;
    vector<vector<int>> test{{1,0}};

    cout << "Ans: " << sol.canFinish(2, test) << endl;

}