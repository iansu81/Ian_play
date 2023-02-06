#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> tmp;
        backtrack(1, n, k, tmp, result);
        return result;
        
    }

    void backtrack(int start, int n, int k, vector<int>& record, vector<vector<int>>& result){
        
        if(record.size() == k) {
            result.push_back(record);
            return;
        }
        

        for(int i = start; i <= n; i++) {
            record.push_back(i);
            backtrack(i+1, n, k, record, result);
            record.pop_back();
        }

    }

};


int main()
{
    Solution sol;
    vector<vector<int>> output = sol.combine(4, 2);
    for(const auto& v: output) {
        std::cout << "[";
        for(const auto& i: v) {
            cout << i <<',';
        }
        std::cout << "]";
        std::cout << endl;
    }
    
}