#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        if(nums.size() == 0)
        {
            return 0;
        }
        //KEY: prefixsum, VALUE: 這個prefixsum出現幾次 
        unordered_map<int, int> counts{{0,1}};
        int prefixsum = 0;
        int ans = 0;
        for(const auto& element:nums)
        {
            //紀錄加上自己之後的prefixsum
            //然後在unordered_map裡面找看看過去有幾個prefixsum-k
            //假設counts[prefixsum -k]＝2,代表前面有兩個位置一直加到目前位置都可以是Ｋ
            prefixsum += element;
            ans += counts[prefixsum-k];
            counts[prefixsum]++;
        }
        return ans;

    }
};


int main(){

    vector<int> nums{1, 1, 1};
    Solution sol;
    sol.subarraySum(nums, 2);
}