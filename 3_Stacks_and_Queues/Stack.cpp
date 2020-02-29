#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack {
private:
    int t, S[MAX];

public:
    void init();
    void push(int x);
    int top();
    void pop();
    bool isEmpty();
    bool isFull();
};

void Stack::init()
{
    t = -1;
}

void Stack::push(int x)
{
    if (!isFull()) {
        t++;
        S[t] = x;
    }
}

int Stack::top()
{
    return S[t];
}

void Stack::pop()
{
    if (!isEmpty())
        t--;
}

bool Stack::isEmpty()
{
    if (t == -1)
        return true;
    return false;
}

bool Stack::isFull()
{
    if (t >= MAX - 1)
        return true;
    return false;
}

int main()
{
    Stack stack;
    stack.init();

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << stack.top() << endl;
    stack.pop();
    stack.push(4);
    cout << stack.top() << endl;
    stack.push(5);
    cout << stack.top() << endl;
    stack.pop();
    stack.pop();
    stack.pop();
    cout << stack.top() << endl;
}
