#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
    public:
        vector<int> partitionLabels(string S)
        {
            //Initialize一個size = 128的vector, 在ASCII裡面, 每個char 都對應到一個int, 所以我們可以在index裡面把char強制轉換成index
            // 所以雖然我們創建了size=128的vector, 但是我們只會用其中26個
            vector<int> record(128,0);
            vector<int> ans;
            //記錄每個char最大的index
            for(int i = 0; i < S.size(); i++)
            {
                record[S[i]] = i;
            }

            //end記錄每一個區間內的char最大的index, 當index跟end我們知道這個區間內的char都在這個index以下,所以我們從這邊cut一個string
            int start =0, end = 0;
            for(int i = 0; i < S.size(); i++)
            {
                end = max(end, record[S[i]] );
                if( i == end){
                    ans.push_back(end - start + 1);
                    start = end+1;
                }
                
            }
            return ans;

        }
};

int main(){

    Solution sol;
    string test = "ababcbacadefegdehijhklij";
    vector<int> result = sol.partitionLabels(test);
    for(auto &val: result){
        cout << val << endl;
    }



}