class MyStack {
private: 
    vector<int> data;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        data.push_back(x);        
    }
    
    int pop() {
        int val = data.back();
        data.pop_back();
        return val;
    }
    
    int top() {
        return data.back();
    }
    
    bool empty() {
        return data.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */