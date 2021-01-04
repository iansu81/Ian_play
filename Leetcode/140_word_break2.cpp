#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return helper(s, dict);
    }

    // 用來append 在dict裡面的string 給vector of string
    // ex: 假設original string 有{"cats and", "cat sand"}, 我們要把dog append上去
    // 變成 {"cats and dog", "cat sand dog"}
    void append_helper(vector<string>& original_string, string append_string)
    {
        for(auto& s : original_string)
        {
            s = s + " " + append_string;
        }
    }

    // 這個function的unordered_set 一定要pass by reference, 不然超慢
    vector<string>& helper(string s, unordered_set<string>& dict)
    {
        // 如果之前已經找過這個s, 就用紀錄的值就好了
        if(record.count(s)) return record[s];


        vector<string> ans;
        // 就算在dict裡面找到s, 也不能直接return, 因為s裡面的子串可能也在dict裡面
        if(dict.count(s))
            ans.push_back(s);

        //這邊都是先找出右邊的子string是不是在dict裡面, 如果是的話, 就把左邊的string拿出來recursively繼續做 
        for(int i = 1; i < s.size(); i++)
        {
            string right = s.substr(i);
            // 如果右邊的不在dictionary裡面, 也不用做下去了, 
            if(!dict.count(right)) continue;

            string left = s.substr(0,i);

            // 接下來找左邊的子串
            vector<string> left_ans = helper(left, dict);
            append_helper(left_ans, right);

            // 這邊不能用push back原因是ans 這個vector<string>裡面是包含了所有s的解, 
            // left_ans只包含了在這個right string之下的所有解, ans是所有right string 的解
            ans.insert(ans.end(), left_ans.begin(), left_ans.end());
        }
        record[s] = ans;
        return record[s];

    }
private: 
    unordered_map<string, vector<string>> record;
};



int main()
{
    string test = "catsanddog";
    vector<string> test_dict = {"cat", "cats", "and", "sand", "dog"};
    
    Solution sol;
    vector<string> ans = sol.wordBreak(test, test_dict);
    // sol.append_helper(test_dict, test);
    for(auto& e : ans)
    {
        cout << e << endl;
    }

}