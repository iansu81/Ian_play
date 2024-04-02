


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        // 先將小孩跟餅乾的數值從小排到大
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
   
        int child_idx = 0;
        int cookie_idx = 0;

        // 因為一個人只能吃一個餅乾, 所以如果餅乾的數值比小孩子要吃的小, 就只能往後找更大的
        while(child_idx < g.size() && cookie_idx < s.size()) {
            if(g[child_idx] <= s[cookie_idx]) child_idx++;
            cookie_idx++;
        }

        return child_idx;
    }
};