#include <bits/stdc++.h>
using namespace std;

class Stack3 {
public:
    Stack3(int size = 300)
    {
        buf = new int[size * 3];
        ptop[0] = ptop[1] = ptop[2] = -1;
        this->size = size;
    }
    ~Stack3()
    {
        delete[] buf;
    }
    void push(int stack_num, int val)
    {
        int idx = stack_num * size + ptop[stack_num] + 1;
        buf[idx] = val;
        ++ptop[stack_num];
    }
    void pop(int stack_num)
    {
        if (!empty(stack_num))
            --ptop[stack_num];
    }
    int top(int stack_num)
    {
        int idx = stack_num * size + ptop[stack_num];
        return buf[idx];
    }
    bool empty(int stack_num)
    {
        return ptop[stack_num] == -1;
    }

private:
    int* buf;
    int ptop[3];
    int size;
}