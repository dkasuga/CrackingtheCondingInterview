#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

struct P {
    int element;
    int min;
};

class Stack {
private:
    int tp;
    P* buf;

public:
    Stack(int size = 1000)
    {
        tp = -1;
        buf = new P[size];
    }
    ~Stack()
    {
        delete[] buf;
    }

    void push(int x)
    {
        if (!isFull()) {
            if (isEmpty()) {
                buf[++tp].element = x;
                buf[++tp].min = x;
            } else {
                int prev_mn = buf[tp].min;
                tp++;
                buf[tp].element = x;
                buf[tp].min = min(x, prev_mn);
            }
        }
    }

    void pop()
    {
        if (!isEmpty())
            tp--;
    }

    int top_element()
    {
        return buf[tp].element;
    }

    int top_min()
    {
        return buf[tp].min;
    }

    bool isFull()
    {
        if (tp >= MAX - 1)
            return true;
        return false;
    }

    bool isEmpty()
    {
        if (tp == -1)
            return true;
        return false;
    }
};

int main()
{
    Stack s;

    s.push(5);
    s.push(8);
    s.push(-2);
    s.push(9);
    s.push(-8);
    s.push(11828);
    s.push(-10);
    cout << s.top_min() << endl;
    s.pop();
    cout << s.top_min() << endl;
    s.pop();
    cout << s.top_min() << endl;
    s.pop();
    cout << s.top_min() << endl;
    s.pop();

}
