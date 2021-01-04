#include <vector>
#include <iostream>
using namespace std;


// 利用兩個pointer來read跟write, i 是read, j write
// 另外額外用一個count來紀錄有幾個char

class Solution {
public:
    int compress(vector<char>& chars) {

        if(chars.size() == 1){
            return chars.size();
        }

        int j = 0;
        int i = 0;
        while(i < chars.size()){
            chars[j] = chars[i];
            int count = 0;
            // 一開始先看相同的char有幾個
            while(chars[j] == chars[i] && i < chars.size() ){
                count ++;
                i++;
            }

            // 當正在遍歷的char只有一個,並不需要額外write一個數字在後面, 直接j++
            if( count == 1){
                j++;
            }
            // 如果不只有一個就要在char後面寫入
            else{
                string str = to_string(count);
                for(auto ch:str){
                  chars[++j] = ch;
                }
                j++;
            }
        }
        return j;
    }
};


int main(){

  // Solution sol;
  // vector<char> v1{}
  // sol.compress(v1);
  string str = to_string(count);
  for(auto ch: str)
  chars[++j] = ch;

}
