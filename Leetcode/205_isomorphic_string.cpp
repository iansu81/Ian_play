class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // Initial 2個vector來記錄字母所對應的號碼
        vector<int> s_record(128, -1);
        vector<int> t_record(128, -1);

        for(int i = 0; i < s.size(); i++) {
            // 因為兩個string 裡面character 必須要對應到
            // 如果沒對應到就錯了
            // The idea is that we need to map a char to another one, for example,
            //  "egg" and "add", we need to constract the mapping 'e' -> 'a' and 'g' -> 'd'. 
            // Instead of directly mapping 'e' to 'a', another way is to mark them with same value, 
            // for example, 'e' -> 1, 'a'-> 1, and 'g' -> 2, 'd' -> 2, this works same.
            if(s_record[s[i]] != t_record[t[i]]) return false;
            s_record[s[i]] = i;
            t_record[t[i]] = i;

        }
        return true;
        
    }
};