// Note: 因為最多只能持有一支股票, 所以只要新的一天比前一天高, 就先賣掉獲利再等下一次更高, ex: [2,3,5]
// 最多應該是5-2 = 3, 但是這結果跟(3-2)+(5-3) 一樣

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProf = 0;
        for( int i = 1 ; i < prices.size() ; i++ ){
            if( prices[i] - prices[i -1] > 0){
                totalProf = totalProf + prices[i] - prices[i-1];
            }
        }
        return totalProf;
    }
};