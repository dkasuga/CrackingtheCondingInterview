#include <bits/stdc++.h>
using namespace std;

bool isReplaceable(string s, string t)
{
    bool foundDifference = false;
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) != t.at(i)) {
            if (foundDifference)
                return false;
            foundDifference = true;
        }
    }

    return true;
}

bool isDeletable(string s, string t)
{
    // s is shorter than t
    int i_s = 0, i_t = 0;
    bool foundDifference = false;
    while (i_s < s.size() && i_t < t.size()) {
        if (s.at(i_s) != t.at(i_t)) {
            if (foundDifference)
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

// merge isReplaceable and isDeletable
bool isConvertable2(string first, string second)
{
    // check length
    if (abs(int(first.size() - second.size())) > 1)
        return false;

    // get shorter and longer string
    string s1 = first.size() < second.size() ? first : second;
    string s2 = first.size() < second.size() ? second : first;

    int index1 = 0;
    int index2 = 0;

    bool foundDifference = false;
    while (index2 < s2.size() && index1 < s1.size()) {
        if (s1.at(index1) != s2.at(index2)) {
            // note that this is the first difference found
            if (foundDifference)
                return false;
            if (s1.size() == s2.size()) // move pointer of shorter one on replace
                index1++;
        } else {
            index1++; // move pointer of shorter one when matching
        }
        index2++; // always move pointer for longer string
    }
    return true;
}

int main()
{
    string s, t;
    cin >> s >> t;
    if (isConvertable2(s, t))
        cout << "Yes" << endl;
    else {
        cout << "No" << endl;
    }
}
