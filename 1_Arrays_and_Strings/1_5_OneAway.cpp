#include <bits/stdc++.h>
using namespace std;

bool isReplaceable(string s, string t)
{
    bool isDifferent = false;
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) != t.at(i)) {
            if (isDifferent)
                return false;
            isDifferent = true;
        }
    }

    return true;
}

bool isDeletable(string s, string t)
{
    // s is shorter than t
    int i_s = 0, i_t = 0;
    bool isDifferent = false;
    while (i_s < s.size() && i_t < t.size()) {
        if (s.at(i_s) != t.at(i_t)) {
            if (isDifferent)
                return false;
            i_t++;
        } else {
            i_s++;
            i_t++;
        }
    }
    return true;
}
bool isConvertable(string s, string t)
{
    if (s.size() == t.size()) {
        return isReplaceable(s, t);
    } else if (s.size() == t.size() - 1) {
        return isDeletable(s, t);
    } else if (s.size() == t.size() + 1) {
        return isDeletable(t, s);
    }
    return false;
}

int main()
{
    string s, t;
    cin >> s >> t;
    if (isConvertable(s, t))
        cout << "Yes" << endl;
    else {
        cout << "No" << endl;
    }
}
