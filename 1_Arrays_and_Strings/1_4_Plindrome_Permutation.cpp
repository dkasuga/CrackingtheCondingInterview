#include <bits/stdc++.h>
using namespace std;

bool isPrindrome1(string s)
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

// change i bit of number
int toggle(int bit_vector, int index)
{
    if (index < 0)
        return bit_vector;

    int mask = 1 << index;
    if ((bit_vector & mask) == 0) {
        bit_vector |= mask;
    } else {
        bit_vector &= ~mask;
    }
    return bit_vector;
}

int createBitVector(string s)
{
    int bit_vector = 0;
    for (char c : s) {
        if (isspace(c))
            continue;
        if (isupper(c))
            c = tolower(c);
        int x = c - 'a';
        bit_vector = toggle(bit_vector, x);
    }
    return bit_vector;
}

// 整数値から1減算したものとと元の数のANDをとり，1bitだけが1になっているかどうかをチェック
bool checkExactlyOneBitSet(int bit_vector)
{
    return (bit_vector & (bit_vector - 1)) == 0;
}

bool isPrindrome2(string s)
{
    int bit_vector = createBitVector(s);
    return bit_vector == 0 || checkExactlyOneBitSet(bit_vector);
}

int main()
{
    string s;
    // 空白無視して読み込む
    getline(cin, s);
    if (isPrindrome2(s))
        cout << "Yes" << endl;
    else {
        cout << "No" << endl;
    }
}