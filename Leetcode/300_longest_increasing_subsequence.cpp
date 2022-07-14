#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // dp[i] 意思是到 i 為止, the longest increase subsequence 
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++) {

                // 只有當後面的數字比前面的大而且(dp前面的+1)>(dp後面的)的時候, 才要update dp[i]
                // 假設nums[5] 比nums[2], numsp[3]都大, 但是dp[2] > dp[3]
                // 我們iterate到dp[3]的時候就不用update前一個結果
                if(nums[i] > nums[j] && (dp[j] + 1 ) > dp[i]) dp[i]=dp[j]+1;
            }
        }
        return *std::max_element(dp.begin(), dp.end()) ;

    }
};




int main() {


}