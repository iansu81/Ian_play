#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <limits.h>
#include <queue>

using namespace std;


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int> > q;
        for(const auto& stone:stones) {
            q.push(stone);
        }
        while(q.size() > 1) {
            int s1 = q.top();
            q.pop();
            int s2 = q.top();
            q.pop();
            q.push(s1-s2);
        }
        return q.top();
    }
};

int main() {
    vector<int> test {2,7,4,1,8,1};
    Solution sol;
    cout << "Ans: " << sol.lastStoneWeight(test) << std::endl;


}