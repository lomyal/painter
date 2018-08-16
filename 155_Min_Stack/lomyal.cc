
// 要点：栈是有状态的，每个元素入栈时将当时的状态保存下来即可

// 1、双栈 T=O(1) S=O(n)
class MinStack {
public:
    void push(int x) {
        if (min.empty() || x <= min.top()) {
            min.push(x);
        }

        dataStack.push(x);
    }

    void pop() {
        if (min.top() == dataStack.top()) {
            min.pop();
        }

        dataStack.pop();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return min.top();
    }

private:
    stack<int> dataStack;
    stack<int> min;
};


// 2、单栈（判断少，但耗费空间，可能也更耗费时间（额外元素的存储时间））
/* old, MLE */
class MinStack {
public:
    void push(int x) {
        if (innerStack.empty()) {
            innerStack.push(make_pair(x, x));
        } else {
            int min = innerStack.top().second;
            innerStack.push(make_pair(x, x < min ? x : min));
        }
    }

    void pop() {
        innerStack.pop();
    }

    int top() {
        return innerStack.top().first;
    }

    int getMin() {
        return innerStack.top().second;
    }

private:
    stack<pair<int, int>> innerStack;
};