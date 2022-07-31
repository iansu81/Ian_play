#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    int characterReplacement(string s, int k) {

        // res: 最長的substring
        int res = 0;

        // 用來記錄char freq的hash map
        unordered_map<char, int> record;

        // 頻率最高的數字
        int maxf = 0;
        for(int i = 0; i < s.size() ; i++) {

            // 去找出目前為止頻率最高的數字
            // 理論上substring 的數量減去頻率最高的數字如果可以==k的話, 
            // 這個substring 就可以成為答案的候選人
            // ex: ABABA, k=2, 把所有B換掉就會變成AAAAA
            maxf = max(maxf, ++record[s[i]]);

            // 因為if裡面的res跟目前iterate的index是一樣的, 會比char的數量少一
            // 原本應該是if((res+1) - max <= k),可簡化成以下寫法
            if(res - maxf < k) res++;

            // 如果要置換的char已經超出K的數量, 就要把原本substring最前面的char remove掉
            else
                record[s[i-res]]--;
        }
        return res;
        
    }
};

int main() {


}