// 建立兩個stack, 一個用來紀錄所有的元素, 一個用來紀錄嚴格遞減的元素


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        all_element.push(x);
        // 比較的時候一定要<= 因為要解決edge case： 如果minstack最小的元素是1,
        // 這時候再push一個1進去, 然後pop出1,這樣後面那個1被pop出來, 前面那個1應該要繼續留著
        if(min_stack.empty() ||x <= min_stack.top() )
        {
            min_stack.push(x);
        }
        
    }
    
    void pop() {
        if(all_element.top() == min_stack.top())
        {
            min_stack.pop();
        }
        all_element.pop();
        
    }
    
    int top() {
        return all_element.top();
        
    }
    
    int getMin() {
        return min_stack.top();
        
    }
private:
    stack<int> all_element;
    stack<int> min_stack;
};

