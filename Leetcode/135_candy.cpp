#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy_dis(ratings.size(), 1);
        int size = ratings.size();
        // 如果只有一個item, 直接return 1 
        if (size < 2) {
            return size;
        }

        // 要確保左右兩邊比正在比較的item大的, 拿到的糖果都比較多
        // 先往右邊先掃一次,
        for(int i = 1; i < size; i++) 
        {
            // 如果下一個比較大, candy就要比現在正在比較的還要+1
            if(ratings[i] > ratings[i-1]) candy_dis[i] = candy_dis[i-1]+1;
        }

        // 再往左邊掃一次
        for(int i = (size -2); i >= 0; i--){
            // 往左邊掃的時候, 因為有可能已經比較大了, 所以不一定要再+1, 要取max
            if(ratings[i] > ratings[i+1]) candy_dis[i] = max(candy_dis[i], candy_dis[i+1]+1);
        }
        return std::accumulate(candy_dis.begin(), candy_dis.end(), 0);
    }
};


int main() {
    vector<int> test{1,2,87,87,87,2,1};
    Solution sol;
    std::cout << "Ans:" << sol.candy(test) << std::endl;


}



