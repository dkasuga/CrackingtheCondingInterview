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
bool checkPermutation(string s, string t)
{
    if (s.size() != t.size())
        return false;

    vector<int> letters(128, 0); // ASCIIと仮定
    for (int i = 0; i < s.size(); i++) {
        letters[s.at(i)]++;
    }
    for (int i = 0; i < t.size(); i++) {
        letters[t.at(i)]--;
        if (letters[t.at(i)] < 0)
            return false;
    }
    return true;
}

int main()
{
    string s, t;
    cin >> s >> t;
    if (checkPermutation(s, t))
        cout << "Yes" << endl;
    else {
        cout << "No" << endl;
    }
}