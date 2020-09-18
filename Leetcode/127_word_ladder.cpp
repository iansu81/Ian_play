#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int step = 0;
        while(!q.empty())
        {
            


        }
    }
};


int main()
{
    string begin = "hit";
    string endWord = "cog";
    vector<string> wordList { "hot", "dot", "dog", "lot", "log", "cog" };
    Solution sol;
    cout << "Ans: " << sol.ladderLength(begin, endWord, wordList);
}

// Example 1 :

//     Input : beginWord = "hit",
//             endWord = "cog",
//             wordList = [ "hot", "dot", "dog", "lot", "log", "cog" ]

//                        Output : 5

//                        Explanation : As one shortest transformation is "hit"->"hot"->"dot"->"dog"->"cog",
//             return its length 5. Example 2 :

//     Input : beginWord = "hit" endWord = "cog" wordList = [ "hot", "dot", "dog", "lot", "log" ]

//             Output : 0

//             Explanation : The endWord "cog" is not in wordList,
//             therefore no possible transformation.