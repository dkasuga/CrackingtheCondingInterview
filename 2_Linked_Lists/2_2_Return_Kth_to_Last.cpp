#include <bits/stdc++.h>
using namespace std;

// Singley Linked List
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

int KthToLast(int k)
{
    Node* cur = nil;
    int num_element = 0;
    while (cur->next != nil) {
        cur = cur->next;
        num_element++;
    }

    int i = 0;
    cur = nil;
    while (cur->next != nil) {
        cur = cur->next;
        i++;
        if (i == num_element - k + 1) {
            return cur->key;
        }
    }
    throw std::out_of_range("k is too large or less than 0.");
}

int KthToLast2(int k)
{
    Node* p1 = nil->next;
    Node* p2 = nil;
    // Move p1 k nodes into the list
    for (int i = 0; i < k - 1; i++) {
        if (p1 == nil)
            throw out_of_range("k is out of range");
        p1 = p1->next;
    }

    // Move them at the same pace. When p1 hits the end, p2 will be at the right element.
    while (p1 != nil) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2->key;
}

Node* KthToLastRecursive(Node* head, int k, int& i)
{
    if (head == nil)
        return NULL;
    Node* nd = KthToLastRecursive(head->next, k, i);
    i = i + 1;
    if (i == k)
        return head;
    return nd;
}

int main()
{
    Init();
    Insert(5);
    Insert(4);
    Insert(3);
    Insert(2);
    Insert(1);
    PrintList();
    int k;
    cin >> k;
    cout << KthToLast(k) << endl;
    // cout << KthToLast2(k) << endl;
    int i = 0;
    Node* nd = KthToLastRecursive(nil->next, k, i);
    cout << nd->key << endl;
    return 0;
}