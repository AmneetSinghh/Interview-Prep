#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        string s;
        cin >> s;

        bool invert = k > 25;
        k %= 26;
        for (char i : s) {
            if (i == '.') {
                cout << " ";
                continue;
            }
            int val = i - 'a' + k;
            val %= 26;
            

            char ch = (char) (islower(i) ? 'a' + val : 'A' + val);
            if (invert) {
                if (islower(ch))ch = (char) toupper(ch);
                else ch = (char) tolower(ch);
            }
            cout << ch;
        }
        cout << endl;
    }
}