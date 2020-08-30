#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>


using namespace std;


class Solution {
public:
    string alienOrder(vector<string>& words) {
        if( words.size() == 0) return "";
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int > status;
        for(int i = 0; i < words.size() ; i++ )
        {
            for(const auto& c : words[i] )
            {
                graph[c] = unordered_set<char>();
                status[c] = 0;
            }
        }


        for(int i = 0 ; i < (words.size() - 1); i++ ){
            string w1 = words[i];
            string w2 = words[i+1];
            int len = min(w1.size(), w2.size());
            for(int j = 0 ; j < len; j++ )
            {
                //w2[j] 應該要 > w1[j] 如果條件成立, 就push 到那個字母的adjacent node, 
                //  而滿足這個條件之後, 比較後面的字母也沒有意義, 所以直接break
                if(w1[j] != w2[j])
                {
                    if(graph[w1[j]].count(w2[j])) return "";
                    graph[w2[j]].insert(w1[j]);
                    break;
                }
                // 解決 ['abc', 'ab'] 這個edge case, 當跑到b 的時候發現w1後面還有字母, w2卻沒有, 代表不是valid
                if( j == min( w1.size(), w2.size()) - 1 && w1.size() > w2.size() ) return "";

                
            }
        }

        // Topological sort
        stack<char> record;

        for(auto element : graph)
        {
            if(!tp_sort_utils(element.first, graph, status, record)) return "";
        }
        
        // 把stack的所有元素從top push出來就是答案, top 是最前面的字母
        string ans;
        while(!record.empty())
        {
            ans = record.top() + ans;
            record.pop();
        }
        return ans;

        
    }

    bool tp_sort_utils(char c, unordered_map<char, unordered_set<char>>& graph, unordered_map<char, int>& status, stack<char>& stk)
    {
        // status == 0 : 還沒被訪問過
        // status == 1 : 被訪問過, 但是還沒被丟到stack 裡面, 正在訪問他的子節點, 如果又再被訪問一次, 代表cyclic, 有問題 => return false
        // status == 2 : 代表已經在stack 裡面了, 
        if(status[c] == 1)
        {
            return false;
        }
        if( status[c] == 2)
        {
            return true;
        }
        status[c] = 1;
        // 訪問c的子節點
        for( char e : graph[c])
        {
            if(!tp_sort_utils(e, graph, status, stk)) return false;
        }

        // 訪問完c的所有子節點, 確定沒問題, 就把c push進去stack然後return true
        status[c] = 2;
        stk.push(c);

        return true;

    }
};



int main(){



}