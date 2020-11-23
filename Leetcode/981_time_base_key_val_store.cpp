#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

class TimeMap
{
// 這邊用兩個unordered_map來紀錄資料, value的部份都是用vector來儲存, 
// time_record裡面vector跟value_record裡面的vector, 相同的index會對應到同一組資料
private: 
    unordered_map<string, vector<int>> time_record;
    unordered_map<string, vector<string>> value_record;
public:
    /** Initialize your data structure here. */
    TimeMap()
    {
    }
    void set(string key, string value, int timestamp)
    {
        time_record[key].push_back(timestamp);
        value_record[key].push_back(value);
    }
    // 先用upper_bound去找出, 在時間的vector中, 比要get的timestamp要大的index, 
    // 這樣代表在index-1的位置處剛好是是小於等於timestamp的數裡面最大的一個, 
    // 如果upper_bound找出來的index,剛好index == 0, 代表說這個vector裡面所有的值,都比timestamp大, 所以無解
    // 這邊不用lower_bound的原因如下:
    // lower_bound是找出比要找的值大於等於的index vector[index] >= value
    // upper_bound是找出比要找的值大於的index, vector[index] > value
    // vector = [1,2,4,5]
    // ex1: 
    // get(3):
    //     upper_bound(3) == index: 2(value == 4)
    //     lower_bound(3) == index: 2(value == 4)

    // get(4)
    //     upper_bound(4) == index : 3 (value == 5)
    //     lower_bound(4) == index: 2(value == 4)
    // 因為題目說我們要找出<=timestamp裡面最大的, 從上面兩個例子可以看出,
    // 在get(3), 跟get(4)裡面, upper_bound的答案都是找到的index-1 
    // 但是lower_bound在get(3)裡面答案是index-1, 在get(4)答案裡面卻是index,
    // 所以利用upper_bound來解這一題會比較方便,
    // 如果題目是要找出小於timestamp的話,用lower_bound就會比較方便
    
    string get(string key, int timestamp)
    {
        if(!time_record.count(key)) return "";
        int index = upper_bound(time_record[key].begin(), time_record[key].end(), timestamp) - time_record[key].begin();
        if(index == 0) return "";
        return value_record[key][index-1];
    }


};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */


int main(){


    TimeMap sol;
    sol.set("foo", "bar", 1);
    cout << "1:" << sol.get("foo", 1) << endl;
    cout << "2:" << sol.get("foo", 3) << endl;
    sol.set("foo", "bar2", 4);
    cout << "3:" << sol.get("foo", 4) << endl;
    cout << "4:" << sol.get("foo", 5) << endl;

}
