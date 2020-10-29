#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;




class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // 一開始當左邊沒有元素的時候優先push到左邊, 或者是比左邊最大的元素小, 也push到左邊
        if( left_heap.empty() || num < left_heap.top())
        {
            left_heap.push(num);
        }
        else{
            right_heap.push(num);
        }

        // 因為我們要永遠維持左右兩邊元素數量相等, 或者是左邊比右邊多一個元素, 這邊就是在balance左右元素數量
        if(right_heap.size() > left_heap.size())
        {
            left_heap.push(right_heap.top());
            right_heap.pop();
        }
        else if((left_heap.size() - right_heap.size()) == 2)
        {
            right_heap.push(left_heap.top());
            left_heap.pop();
        }
    }
    
    // 因為我們永遠維持左邊比右邊多一個元素（median就是左邊的top), 
    // 或者左邊跟右邊元素數量相等（median就是左右兩邊的top除以2）
    double findMedian() {
        if(left_heap.size() > right_heap.size()) return left_heap.top();
        else{
            return (left_heap.top() + right_heap.top()) / 2.0;
        }
        
    }
private:
    // 用兩個heap來儲存, 左邊的top是左邊heap最大的, 右邊的top是右邊heap最小的
    priority_queue<int, vector<int>, greater<int> > right_heap;
    priority_queue<int, vector<int>, less<int> > left_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


int main(){
    MedianFinder medfind;
    medfind.addNum(1);
    // cout << "Median: " << medfind.findMedian() << endl;
    medfind.addNum(2);
    // cout << "Median: " << medfind.findMedian() << endl;
    medfind.addNum(3);
    // cout << "Median: " << medfind.findMedian() << endl;

}