#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


// 公式: tail = (head + 在queue裡面的元素數量  - 1) % array的size 
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        m_array_ = new int[k];
        size_ = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        num_elements_++;
        m_array_[(head_+num_elements_-1)%size_] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        head_ = (head_+1)%size_;
        num_elements_--;
        return true;   
    }
    
    int Front() {

        return isEmpty() ? -1 : m_array_[head_];
    }
    
    int Rear() {
        return isEmpty() ? -1 : m_array_[(head_+num_elements_-1)%size_];
    }
    
    bool isEmpty() {
        return (num_elements_ == 0);
    }
    
    bool isFull() {
        return (num_elements_ == size_);
    }
    ~MyCircularQueue() {

        delete [] m_array_;
    }
// private:
    int size_ = 0;
    int num_elements_ = 0;
    int head_ = 0;
    int* m_array_;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {

    MyCircularQueue test(8);
    test.enQueue(3);
    std::cout << test.head_ << std::endl;
    test.enQueue(9);
    std::cout << test.head_ << std::endl;
    test.enQueue(5);
    std::cout << test.head_ << std::endl;
    test.enQueue(0);
    std::cout << test.head_ << std::endl;
    test.deQueue();
    std::cout << test.head_ << std::endl;
    test.deQueue();
    std::cout << test.head_ << std::endl;
    // std::cout << "REAR: " << test.Rear() << std::endl;

}