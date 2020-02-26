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

bool isUniqueChars(string str)
{
    if (str.size() > 128)
        return false;

    vector<bool> char_set(128, false);
    for (int i = 0; i < str.size(); i++) {
        char c = str.at(i);
        if (char_set[c])
            return false;
        char_set[c] = true;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    if (isUniqueChars(s))
        cout << "Yes" << endl;
    else {
        cout << "No" << endl;
    }
}