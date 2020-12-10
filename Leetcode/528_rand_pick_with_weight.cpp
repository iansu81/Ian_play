#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <stdlib.h>  

using namespace std;



// 建立一個vector prefix sum把到目前index的所有數字加起來
// 最後一個數字就是所有的weight 之和, 然後generate 一個數字去mod這個weight和
// 這樣就會產生一個數字是在0~(sum of wight-1), 接下來利用upper_bound去找比這個數字大的第一個index, 即為答案
class Solution {
public:
    Solution(vector<int>& w) {
        current_sum = 0;
        for(const auto& ele: w)
        {
            prefix_sum.push_back(current_sum += ele);
        }
    }
    
    int pickIndex() {
        int random_pick = rand() % current_sum;
        return (upper_bound(prefix_sum.begin(), prefix_sum.end(), random_pick) - prefix_sum.begin());
        
    }
private:
    vector<int> prefix_sum;
    int current_sum;
};

int main()
{
    
    vector<int> test{1,3};
    Solution sol(test);
    
}
