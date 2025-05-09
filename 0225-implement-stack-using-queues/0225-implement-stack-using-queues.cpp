class MyStack {
    private:
     queue<int> q1;
     queue<int> q2;
public:
    MyStack() {
      
    } 
    
    void push(int x) {
        if(q1.empty())
        {
            q1.push(x);
        }
        else{
       while(!q1.empty())
       {
        int y=q1.front();
        q2.push(y);
        q1.pop();
       }
       q1.push(x);
       while(!q2.empty())
       {
         int y=q2.front();
         q1.push(y);
         q2.pop();
       }


        }
    }
    
    int pop() {
        int x=q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
     return    q1.front();
    }
    
    bool empty() {
        return q1.empty();
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