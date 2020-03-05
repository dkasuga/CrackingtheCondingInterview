#include <bits/stdc++.h>
using namespace std;

bool isPrindrome(string s)
{
    map<char, int> cnt;
    for (char c : s) {
        if (isspace(c)) {
            continue;
        }
        if (isupper(c))
            c = tolower(c);
        if (!cnt.count(c))
            cnt[c] = 1;
        else {
            cnt[c]++;
        }
    }

    int num_odd = 0;
    for (auto [key, value] : cnt) {
        if (value % 2 == 1) {
            num_odd++;
        }
    }

    if (num_odd <= 1)
        return true;
    else {
        return false;
    }
}

int main()
{
    string s;
    // 空白無視して読み込む
    getline(cin, s);
    if (isPrindrome(s))
        cout << "Yes" << endl;
    else {
        cout << "No" << endl;
    }
}