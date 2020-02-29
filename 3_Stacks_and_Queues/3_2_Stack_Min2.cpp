#include <bits/stdc++.h>
using namespace std;

const int INF_32 = 1LL << 30;

class StackWithMin {
private:
    stack<int> s_element;
    stack<int> s_min;

public:
    void push(int x)
    {
        s_element.push(x);
        if (min() > x) // this->min()
            s_min.push(x);
    }

    int top()
    {
        return s_element.top();
    }

    void pop()
    {
        if (s_min.top() == s_element.top())
            s_min.pop();
        if (!s_element.empty()) {
            s_element.pop();
        }
    }

    int min()
    {
        if (s_min.empty()) {
            return INF_32;
        } else {
            return s_min.top();
        }
    }

    bool empty()
    {
        return s_element.empty();
    }
};

int main()
{
    StackWithMin s;
    s.push(-10);
    s.push(4);
    s.push(1);
    s.push(8);
    s.push(-2);

    while (!s.empty()) {
        cout << s.min() << endl;
        s.pop();
    }
}