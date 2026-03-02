#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int val;
    int min;
    Node *next;

    Node(int x, int y, Node *n) {
        val = x;
        min = y;
        next = n;
    }
} Node;


class MinStack {
public:
    Node *stack;
    MinStack() {
        stack = nullptr;
    }
    
    void push(int val) {
        if (stack == nullptr)
            stack = new Node(val, val, nullptr);
        else {
            Node *tmp = stack;
            stack = new Node(val, min(val, tmp->min), tmp);
        }
    }
    
    void pop() {
        if (stack == nullptr)
            return;
        Node *tmp = stack->next;
        delete stack;
        stack = tmp;
    }
    
    int top() {
        if (stack == nullptr)
            return -1;
        return stack->val;
    }
    
    int getMin() {
        if (stack == nullptr)
            return -1;
        return stack->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */