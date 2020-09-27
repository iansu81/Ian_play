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
        // 先把要查的字丟到unordered_set, 這樣查找時間比較短
        unordered_set<string> dict(wordList.begin(), wordList.end());
        // 如果endword不在wordlist裡面, 代表永遠找不到
        if (!dict.count(endWord)) return 0;
        // 做ＢＦＳ
        queue<string> q;
        q.push(beginWord);
        // 記錄總共要幾層
        int step = 0;
        while(!q.empty())
        {
            // step一定要在這裡＋＋,每掃過一層,才可以＋1
            step++;
            // 遍歷同一層裡面的word
            for( int q_size = q.size(); q_size > 0; q_size--)
            {
                string word = q.front();
                q.pop();
                // 每次都置換word裡面的一個字母,從a換到z
                for (int i = 0; i < word.size(); i++)
                {
                    char ch = word[i];
                    for (char j = 'a'; j <= 'z'; j++)
                    {
                        word[i] = j;
                        // 如果找到endword直接return 現在step+1(endword)
                        if (word == endWord)
                            return ++step;
                        // 如果沒找到endword但是找到在dictionary裡面middle word的話,就把它push進去queue裡面
                        // 把這個middle word從dictionary移除的原因是因為,如果之後我們又找回這個word那這條路一定不是最短,
                        // 所以一找到就把它移除掉
                        if (dict.count(word))
                        {
                            q.push(word);
                            dict.erase(word);
                        }
                    }

                    word[i] = ch;
                }
            }


        }
        return 0;
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