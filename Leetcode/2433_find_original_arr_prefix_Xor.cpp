// 概念 : A ^ B = C => apply A ^ to both end => A ^ A ^ B = A ^ C => B = A ^ C cause A ^ A = 0
//  pref[i] = pref[i-1] ^ A[i] => 左右同^ pref[i-1] => pref[i-1] ^ pref[i] = A[i] 且XOR滿足交換率 => pref[i] ^ pref[i-1] = A[i]
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {

        // 解法1: 自己想的, Drawback: 難看
        // vector<int> result;
        // if(pref.size() == 1) return pref;
        // for(int i = (pref.size()-1) ; i > 0;i--){
        //     int temp = pref[i-1] ^ pref[i];
        //     result.push_back(temp);
        // }
        // result.push_back(pref[0]);
        // reverse(result.begin(), result.end());
        // return result;


        // 解法2: 快, 不管是一個元素或多個元素, 第一個element都不用動, 所以就不用像上面寫很多edge case check
        for(int i = pref.size()-1; i > 0; --i) pref[i] ^= pref[i-1];

        return pref;
    }
};