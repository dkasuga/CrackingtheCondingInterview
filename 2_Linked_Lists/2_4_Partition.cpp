#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* next;
};

Node* nil;

Node* ListSearch(int key)
{
    Node* cur = nil->next;
    while (cur != nil && cur->key != key) {
        cur = cur->next;
    }
    return cur;
}

void Init()
{
    nil = new Node();
    nil->next = nil;
}

void Insert(int key)
{
    Node* x = new Node();
    x->key = key;
    x->next = nil->next;
    nil->next = x;
}

void DeleteKey(int key)
{
    Node* cur = nil->next;
    while (cur->next != nil) {
        if (cur->next->key == key) {
            cur->next = cur->next->next;
            break;
        }
        cur = cur->next;
    }
}

void PrintList()
{
    Node* cur = nil->next;
    int isf = 0;
    while (1) {
        if (cur == nil)
            break;
        if (isf++ > 0)
            cout << " ";
        cout << cur->key;
        cur = cur->next;
    }
    cout << endl;
}

void Partition1(int key) // 空間
{
    Node *left_start, *left_end, *right_start, *right_end;
    left_start = nullptr;
    right_start = nullptr;

    Node* cur = nil;
    while (cur->next != nil) {
        if (cur->next->key < key && left_start == nullptr) {
            left_start = cur->next;
            left_end = cur->next;
        } else if (cur->next->key >= key && right_start == nullptr) {
            right_start = cur->next;
            right_end = cur->next;
        } else if (left_start != nullptr && cur->key >= key && cur->next->key < key) {
            left_end->next = cur->next;
            right_end = cur;
        } else if (right_start != nullptr && cur->key < key && cur->next->key >= key) {
            right_end->next = cur->next;
            left_end = cur;
        }

        cur = cur->next;
    }
    if (cur->key < key)
        left_end = cur;
    else {
        right_end = cur;
    }

    left_end->next = right_start;
    nil->next = left_start;
    right_end->next = nil;
}

int main()
{
    Init();
    Insert(1);
    Insert(2);
    Insert(10);
    Insert(5);
    Insert(8);
    Insert(5);
    Insert(3);
    Insert(10);
    Insert(4);
    Insert(100);
    Insert(95);
    PrintList();
    Partition1(5);
    PrintList();
}