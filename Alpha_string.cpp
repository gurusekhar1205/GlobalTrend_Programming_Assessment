#include <bits/stdc++.h>
using namespace std;
bool isvalid( string &s) {
    for (int i = 0; i < s.size(); ++i) {
        if (!((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))) {
            return false;  
        }
    }
    return true;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << isvalid(s) << endl;
    return 0;
}