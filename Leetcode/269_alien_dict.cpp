#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>


using namespace std;


class Solution {
public:
    string alienOrder(vector<string>& words) {
        if( words.size() == 0) return "";
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int > indegree;
        for(int i = 0; i < words.size() ; i++ )
        {
            for(const auto& c : words[i] )
            {
                graph[c] = unordered_set<char>();
                indegree[c] = 0;
            }
        }


        for(int i = 0 ; i < (words.size() - 1); i++ ){
            string w1 = words[i];
            string w2 = words[i+1];
            int len = min(w1.size(), w2.size());
            for(int j = 0 ; j < len; j++ )
            {
                //w2[j] 應該要 > w1[j] 
                if(w1[j] != w2[j])
                {
                    if(graph[w1[j]].count(w2[j])) return "";
                    graph[w2[j]].insert(w1[j]);
                    break;
                }
                if( j == min( w1.size(), w2.size()) && w1.size() > w2.size() ) return "";
            }
        }

        


        
    }
};



int main(){



}