/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    stack<int> inS;
    stack<int> outS;
    MyQueue() {

    }
    
    void push(int x) {
        inS.push(x);
    }
    
    int pop() {
        if (outS.empty())
        {
            while (!inS.empty())
            {
                outS.push(inS.top());
                inS.pop();
            }
            
        }
        int res = outS.top();
        outS.pop();
        return res;
        

    }
    
    int peek() {
        int res = this->pop();
        outS.push(res);
        return res;
    }
    
    bool empty() {
        return inS.empty()&&outS.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

