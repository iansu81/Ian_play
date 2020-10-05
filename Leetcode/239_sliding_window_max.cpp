#include <vector>
#include <algorithm>
#include <deque>
#include<iostream>
using namespace std;


//  Monotonic Queue:
// 在這個deque裡面,最前面的數字一定是最大的,
// 當要push一個數字進來的時候,有兩種case:
// 1. push進來的數字比最小的數字還要小(最右邊的數字)  ＝> 直接append,
// 2. push進來的數字比其中一些數字要大  ＝> 把比push進來數字小的數全部pop出去之後再append

class Mono_queue
{
    public:
        int get_max(){ return record_.front();}

        void pop_front() { record_.pop_front();}

        void push(int e) {
            while(!record_.empty() && e > record_.back() ) record_.pop_back();
            record_.push_back(e);
        }
    private:
        deque<int> record_;

};



class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        Mono_queue moq;
        vector<int> result;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            moq.push(nums[i]);

            // 假設k = 3,代表起碼要push三個元素進去mono queue之後才可以開始找最大的, 也就是說要等i = 2元素push進去之後才可以開始找
            if( (i-k+1) >= 0)
            {
                result.push_back(moq.get_max());

                // 如果mono queue裡面最大的元素（最左邊的元素）剛好是在我們shift i之後要被移除的,  在這邊pop掉
                if(moq.get_max() == nums[i-k+1] )
                {
                    moq.pop_front();
                }
            }
        }
        return result;

    }
};


int main(){

    // Test  for monotonic queue.

    // Mono_queue moq;
    // moq.push(3);
    // moq.push(5);
    // moq.push(-3);
    // for(auto e: moq.record_)
    // {
    //     cout << e << ',';
    // }

    vector<int> test{1, 3, -1, -3, 5, 3, 6, 7};
    Solution sol;
    vector<int> result = sol.maxSlidingWindow(test, 3);
    for(const auto & e: result)
    {
        cout << e << ',';
    }
    cout << endl;


}