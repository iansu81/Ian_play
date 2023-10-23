#include <stack>
#include <iostream>
#include <vector>

using namespace std;

// 利用Stack去記錄數字, 如果遇到運算符號, 就pop出來做
// 注意: 如果第一個if是用if(isdigit(s[0]))來確認是不是數字的話, 遇到負數會有問題
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> record;
        for(auto s: tokens) {  
            if( s == "+"){
                int temp1 = record.top();
                record.pop();
                int temp2 = record.top();
                record.pop();
                record.push(temp2+temp1);
            }
            else if( s == "-"){
                int temp1 = record.top();
                record.pop();
                int temp2 = record.top();
                record.pop();
                record.push(temp2-temp1);

            }
            else if( s == "*"){
                int temp1 = record.top();
                record.pop();
                int temp2 = record.top();
                record.pop();
                record.push(temp2*temp1);
                
            }
            else if( s == "/"){
                int temp1 = record.top();
                record.pop();
                int temp2 = record.top();
                record.pop();
                record.push(temp2/temp1);   
            }
            else record.push(stoi(s));

        }
        return record.top();
    }
};

int main()
{
    vector<string> test{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution sol;
    cout << "Ans: " << sol.evalRPN(test) << endl;


}