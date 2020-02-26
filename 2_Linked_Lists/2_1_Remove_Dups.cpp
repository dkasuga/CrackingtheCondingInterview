#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;
const int MOD = 1000000007;

typedef long long ll;

ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
ll LCM(ll x, ll y)
{
    return x * y / GCD(x, y);
}

using Graph = vector<vector<int>>;
typedef pair<int, int> P;

struct Node {
    int key;
    Node *next, *prev;
};

// loop from nil to nil
Node* nil; // sentinel

Node* listSearch(int key)
{
    Node* cur = nil->next; // follow from the next element of nil
    while (cur != nil && cur->key != key) {
        cur = cur->next;
    }
    return cur;
}

void init()
{
    // nil = (Node*)malloc(sizeof(Node));
    nil = new Node();
    nil->next = nil;
    nil->prev = nil;
}

void printList()
{
    Node* cur = nil->next;
    int isf = 0;
    while (1) {
        if (cur == nil)
            break;
        if (isf++ > 0)
            printf(" ");
        printf("%d", cur->key);
        cur = cur->next;
    }
    printf("\n");
}

void deleteNode(Node* t)
{
    if (t == nil)
        return; // not process if t is nil
    t->prev->next = t->next;
    t->next->prev = t->prev;
    delete t;
}

void deleteFirst()
{
    deleteNode(nil->next);
}

void deleteLast()
{
    deleteNode(nil->prev);
}

void deleteKey(int key)
{
    // delete node searched
    deleteNode(listSearch(key));
}

void insert(int key)
{
    Node* x = new Node();
    x->key = key;
    // add element right after nil
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

int main()
{
    init();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        insert(element);
    }
    printList();

    set<int> record;
    Node* cur = nil->next;
    while (cur != nil) {
        if (!record.count(cur->key))
            record.insert(cur->key);
        else {
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
            record.erase(cur->key);
        }
        cur = cur->next;
    }

    printList();
}