#include <vector>
#include <iostream>
using namespace std;

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
            while(chars[j] == chars[i] && i < chars.size() ){
                count ++;
                i++;
            }
            if( count == 1){
                j++;
            }
            else{
                string str = to_string(count);
                for(auto ch:str){
                  chars[++j] = c;
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
