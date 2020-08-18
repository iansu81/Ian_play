#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        //利用一個stack來記錄所有’（‘位置
        stack<int> record;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(') record.push(i);
            if(s[i] == ')'){
                //當stack不為空,遇到‘)’的時候代表是一個合法的')'
                //不然就是一個不合法的')'.在這邊把')'標記為‘＊’
                if(!record.empty())
                {
                    record.pop();
                }
                else{
                    s[i] = '*';
                }
            }
        }
        // 處理剩下不合法的'(',把他們全部標記為'*'
        while(!record.empty())
        {
            int index = record.top();
            record.pop();
            s[index] = '*'; 
            
        }
        // 把所有不合法的‘＊’都刪除掉
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};


int main() {
    string test1 = "lee(t(c)o)de)";
    string test2 = "a)b(c)d";
    string test3 = "))((";
    string test4 = "(a(b(c)d)";

    Solution sol;
    sol.minRemoveToMakeValid(test1);
}