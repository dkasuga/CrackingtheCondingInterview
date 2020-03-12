#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

struct Node {
    int key;
    Node* next;
};

Node* nil;

void init()
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

bool DeleteNode(Node* n)
{
    if (n == nil || n.next == nil) {
        return false;
    }
    Node* next = n->next;
    n->key = next->key;
    n->next = next->next;
    return true;
}

int main()
{
    Init();
    Insert(5);
    Insert(4);
    Insert(3);
    Insert(2);
    Insert(1);
    int k;
}