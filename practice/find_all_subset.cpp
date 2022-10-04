/*Given as input a 1D time series dataset D = (x_0, x_1, ..., x_{N-1}), define a steady window of size K to be any sub-series W_i = (x_i, x_{i+1},..., x_{i+K-1}) such that max(W) - min(W) <= C, for a given "steadiness threshold" C.
Find all the steady windows given D, C, and K.
D = [2,4,1,6,3,2,4,2,3,1,5,7,6], K = 3, C = 2
           r
W_4 = [3,2,4]
W_5 = [2,4,2]
W_6 = [4,2,3]
W_7 = [2,3,1‍‌‍‌‍‍‌‍‍‍‍‌‍‍‍‌‍‍‌]
W_10 = [5,7,6]

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <deque>


using namespace std;


vector<vector<int>> find_all_subset_meet_req(vector<int> input, int K, int C) {
    vector<vector<int>> result;
    deque<int> max_val;
    deque<int> min_val;
    for(int i = 0; i < input.size(); i++){
        while(!max_val.empty() && input[i] > max_val.back() ) {
            record_.pop_back();

        }
        
        
        
        while(!record_.empty() && e > record_.back() ) record_.pop_back();

        
    }



    return result;


}


int main() {
    vector<int> test{2,4,1,6,3,2,4,2,3,1,5,7,6};
    vector<vector<int>> result = find_all_subset_meet_req(test, 3, 2);
    for(const auto& v:result){
        for(const auto& e: v) {
            std::cout << e << ',';
        }
        std::cout << endl;
    }


}